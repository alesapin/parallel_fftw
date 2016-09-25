from subprocess import check_output
from mpl_toolkits.mplot3d import axes3d, Axes3D
import matplotlib.pyplot as plt

BINARY_NAME = "FFTW_MPI"
RUNNER_NAME = "mpirun"

def is_prime(num):
    if num <= 0: return False
    return all(num % i for i in xrange(2, num))

def single_run(proc_num, size):
    command = [RUNNER_NAME, "-np", str(proc_num), BINARY_NAME, "-s", str(size)]
    result = check_output(command)
    return proc_num, size, float(result)

def plot(result):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    x,y,z=zip(*result)
    ax.scatter(x,y,z)
    ax.set_xlabel('ProcNum')
    ax.set_ylabel('ElemsSize')
    ax.set_zlabel('ElapsedTime')
    plt.show()

def main():
    result = []
    for proc_num in [int(pow(2,i)) for i in xrange(0, 8)]:
        print 'proc_num: ' + str(proc_num)
        for size in [int(pow(2,i)) for i in xrange(10, 25)]:
            if size / proc_num > 128:
                print 'size:' + str(size)
                thriple = single_run(proc_num, size)
                result.append(thriple)
    plot(result)

if __name__ == "__main__":
    main()
