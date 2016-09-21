#include <mpi.h>
#include "fftw3.h"
#include "fftw3-mpi.h"
#include <stdio.h>

#define SIZE 100

int main(int argc, char **argv)
{
    fftw_plan plan;
    fftw_complex in[SIZE], out[SIZE];
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    fftw_mpi_init();
    plan = fftw_mpi_plan_dft_1d(SIZE, in, out, MPI_COMM_WORLD, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    /* get local data size and allocate */
    MPI_Finalize();
}
