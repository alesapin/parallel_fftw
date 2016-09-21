#include "fftw3-mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    fftw_plan plan;
    fftw_complex *data;
    ptrdiff_t alloc_local, local_n0, local_0_start, i, j;

    MPI_Init(&argc, &argv);
    fftw_mpi_init();

    /* get local data size and allocate */
    MPI_Finalize();
}
