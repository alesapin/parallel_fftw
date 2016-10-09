# -*- coding: utf-8 -*-
import subprocess
from argparse import ArgumentParser
import time
import os
import logging

BINARY_NAME = "FFTW_MPI"
RUNNER_NAME = "sbatch"

def check_output(command):
    cmd = subprocess.Popen(command, stdout=subprocess.PIPE)
    output = cmd.communicate()[0]
    return output

def is_prime(num):
    if num <= 0: return False
    return all(num % i for i in xrange(2, num))

def get_job_id(stroka):
    arr = [int(s) for s in stroka.split() if s.isdigit()]
    return arr[0]

def single_run(cluster, bin_path, proc_num, size):
    file_name = str(cluster) + "_" + str(bin_path) + "_" + str(proc_num) + "_" + str(size) + "_" + str(int(time.time()))
    command = [RUNNER_NAME, "-o", file_name, "-n" + str(proc_num), "-p", cluster, "ompi", bin_path, "-s", str(size)]
    print command
    job_id = get_job_id(check_output(command))
    logging.info("Job runned: " + str(job_id))
    return file_name, job_id

def get_queued_jobs(user):
    command = ['squeue', '-u', user]
    output = check_output(command)
    strings = output.split('\n')[1:]
    result = set([])
    for row in strings:
        if row:
            jobid = row.split(" ")[0]
            result.add(int(jobid))
    return result

def waiter(user, jobs_runned):
    time.sleep(1)
    runned_jobs_dict = {}
    for job in jobs_runned:
        runned_jobs_dict[job] = True
    while sum(runned_jobs_dict.values()):
        current_jobs = get_queued_jobs(user)
        logging.info("Current jobs:" + str(current_jobs))
        for job, val in runned_jobs_dict.iteritems():
            if job not in current_jobs and val:
                runned_jobs_dict[job] = False
                logging.info("Job № {0} finished".format(job))
        unfinised_jobs = [jobid for jobid in runned_jobs_dict if runned_jobs_dict[jobid]]
        logging.info("Runned jobs: {0}".format(unfinised_jobs))
        time.sleep(2)
    return True

def collect_result(file_list):
    result = []
    for fname in file_list:
        with open(fname,'r') as res_file:
            row = res_file.readline()
            arr = row.strip().split('\t')
            result.append((int(arr[0]), int(arr[1]), float(arr[2]), int(arr[3])))
        os.remove(fname)
    return result

def main():
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(message)s", datefmt="%H:%M:%S")
    parser = ArgumentParser(description="Simple fftw_mpi runner")
    parser.add_argument("-c","--cluster", help="Specify cluster to run", type=str)
    parser.add_argument("-b","--binpath", help="Specify binary path", type=str)
    parser.add_argument("-m","--maxproc", help="Maximum process number", type=int)
    parser.add_argument("-u","--username", help="User which run the programm", type=str)
    parser.add_argument("-r","--result", help="Result file name", type=str)
    args = parser.parse_args()
    files =[]
    jobs = []
    for proc_num in [int(pow(2,i)) for i in xrange(3, 10)]:
        if proc_num > args.maxproc:
            break
        for size in [int(pow(2,i)) for i in xrange(10, 25)]:
            if size / proc_num > 128:
                fname, jobid = single_run(args.cluster, args.binpath, proc_num, size)
                files.append(fname)
                jobs.append(jobid)
                if waiter(args.username, jobs):
                    arr = collect_result(files)
                    with open(args.result, 'a') as res_file:
                        for row in arr:
                            res_file.write("{0}\t{1}\t{2}\t{3}\n".format(row[0],row[1],row[2],row[3]))
                jobs = []
                files = []


if __name__ == "__main__":
    main()
