# -*- coding: utf-8 -*-
import subprocess
from argparse import ArgumentParser
import time
import os
import logging
import threading

#mpisubmit.bg --env="BG_SHAREDMEMPOOLSIZE=400" -n 256 -m vn --stderr=err.log FFTW_MPI -- -s 2147483648
BINARY_NAME = "FFTW_MPI"
RUNNER_NAME = "mpisubmit.bg"

def is_prime(num):
    if num <= 0: return False
    return all(num % i for i in xrange(2, num))

def get_started_job(stroka):
    return stroka.split(' ')[3]

def single_run(bin_path, proc_num, size):
    file_name = str(bin_path) + "_" + str(proc_num) + "_" + str(size) + "_" + str(int(time.time()))
    command = [RUNNER_NAME, "--env", '"BG_SHAREDMEMPOOLSIZE=256"', "-n", str(proc_num), "--stdout",
               file_name, bin_path, "--", "-s", str(size)]
    logging.info("Job started:" + get_started_job(subprocess.check_output(command)))
    return file_name

def get_queued_jobs():
    result = subprocess.Popen('llq | tail -n 1 | cut -d" " -f1', shell=True, stdout=subprocess.PIPE).stdout.read()
    try:
        value = int(result)
    except ValueError:
        value = 0
    return value

def waiter():
    time.sleep(5)
    jobs = get_queued_jobs()
    while jobs != 0:
        logging.info("Jobs executing: {0}".format(jobs))
        jobs = get_queued_jobs()
        time.sleep(5)
    return True

def collect_result(file_list):
    result = []
    for fname in file_list:
        with open(fname, 'r') as res_file:
            row = res_file.readline()
            if row:
                arr = row.strip().split('\t')
                result.append((int(arr[0]), int(arr[1]), float(arr[2])))
        os.remove(fname)
    return result

def main():
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(message)s", datefmt="%H:%M:%S")
    parser = ArgumentParser(description="Simple fftw_mpi runner")
    parser.add_argument("-b","--binpath", help="Specify binary path", type=str)
    parser.add_argument("-m","--maxproc", help="Maximum process number", type=int)
    parser.add_argument("-r","--result", help="Result file name", type=str)
    args = parser.parse_args()
    files =[]
    waiter_thread = threading.Thread(target=waiter)
    waiter_thread.start()
    for proc_num in [int(pow(2,i)) for i in xrange(3, 10)]:
        if proc_num > args.maxproc:
            break
        for size in [int(pow(2,i)) for i in xrange(15, 30)]:
            if size / proc_num >= 128:
                fname = single_run(args.binpath, proc_num, size)
                files.append(fname)

    while waiter_thread.isAlive():
        time.sleep(1)
    arr = collect_result(files)
    with open(args.result, 'a') as res_file:
        for row in arr:
            res_file.write("{0}\t{1}\t{2}\t\n".format(row[0],row[1],row[2]))

if __name__ == "__main__":
    main()
