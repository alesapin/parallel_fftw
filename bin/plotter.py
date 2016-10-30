import os
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
from scipy.interpolate import griddata
from matplotlib.ticker import LinearLocator, FormatStrFormatter

def read_file(fpath):
    result = []
    with open(fpath,'r') as f:
        for line in f:
            result.append(tuple(float(n) for n in line.split('\t')))
    return result

def read_seq_file(fpath):
    result = {}
    with open(fpath,'r') as f:
        for line in f:
            spl = line.split('\t')
            num, time = int(spl[0]), float(spl[1])
            result[num] = time
    return result

def count_efficiency(size, procs, parallel_time, seq_time):
    s = seq_time / parallel_time
    print 's ' + str(s)
    print 'proc num ' + str(procs)
    print 'input size ' + str(size)
    print 'result: ' + str(s / procs)
    return s / procs * 100

def plot_3d(x, y, z, xlabel, ylabel, zlabel):
    X = np.asarray(x)
    Y = np.asarray(y)
    Z = np.asarray(z)
    xi = np.linspace(X.min(),X.max(),100)
    yi = np.linspace(Y.min(),Y.max(),100)
    zi = griddata((X, Y), Z, (xi[None,:], yi[:,None]), method='cubic')
    xig, yig = np.meshgrid(xi, yi)

    print zi
    surf = ax.plot_surface(xig, yig, zi, cmap=cm.rainbow_r, rstride=1, cstride=1)
    cbar = fig.colorbar(surf, aspect=10)
    cbar.remove()
    #cbar.ax.set_yticklabels([str(i) for i in xrange(int(Z.min()), int(Z.max()+1))])
    ax.set_zlim(zmin=0)
    ax.set_ylim(ymin=0)
    ax.set_xlim(xmin=0)
    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.set_zlabel(zlabel)
    plt.show()


if __name__ == "__main__":
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    data = read_file('result_smp_send_recv.txt')
    seq_dict = read_seq_file('result_seq.txt')
    print seq_dict
    effective_z = []
    for row in data:
        effective_z.append(count_efficiency(row[0], row[1], row[2], seq_dict[row[0]]))
    print effective_z
    x,y,z = zip(*data)
    plot_3d(x,y,z,'Data Size', 'Procs Num', 'Elapsed time (sec)')

