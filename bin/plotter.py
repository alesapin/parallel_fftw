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
            result.append((float(n) for n in line.split('\t')))
    return result

if __name__ == "__main__":
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    data = read_file('result_smp.txt')
    x,y,z = zip(*data)
    X = np.asarray(x)
    Y = np.asarray(y)
    Z = np.asarray(z)
    xi = np.linspace(X.min(),X.max(),100)
    yi = np.linspace(Y.min(),Y.max(),100)
    zi = griddata((X, Y), Z, (xi[None,:], yi[:,None]), method='cubic')
    xig, yig = np.meshgrid(xi, yi)

    surf = ax.plot_surface(xig, yig, zi, cmap=cm.rainbow_r, rstride=1, cstride=1)
    cbar = fig.colorbar(surf, shrink=0.8, aspect=10)
    cbar.remove()
    #cbar.ax.set_yticklabels([str(i) for i in xrange(int(Z.min()), int(Z.max()+1))])
    ax.set_zlim(zmin=0)
    ax.set_ylim(ymin=0)
    ax.set_xlim(xmin=0)
    ax.set_xlabel('Data Size')
    ax.set_ylabel('Processors Num')
    ax.set_zlabel('Elapsed time(sec)')
    plt.show()

