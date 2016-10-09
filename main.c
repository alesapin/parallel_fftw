#include <mpi.h>
#include "fftw3.h"
#include "fftw3-mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

double rand_double() {
    return (double)rand()/(double)RAND_MAX;
}

ptrdiff_t get_size(int argc, char** argv) {
    char c;
    char *opt_val = NULL;
    while ((c = getopt (argc, argv, "s:")) != -1) {
        switch(c) {
        case 's':
            opt_val = optarg;
            return strtol(opt_val, NULL, 10);
            break;
        default:
            return 0;
        }
    }
}

int main(int argc, char **argv) {


    ptrdiff_t total_size = get_size(argc, argv);

    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    fftw_mpi_init();

    ptrdiff_t local_start, local_size, dum1, dum2;
    double time_start, time_end;
    fftw_complex *in_data, *out_data;
    fftw_plan plan;
    ptrdiff_t alloc_size = fftw_mpi_local_size_1d(total_size, MPI_COMM_WORLD, FFTW_FORWARD , FFTW_ESTIMATE, &local_size, &local_start, &dum1, &dum2);
    in_data = fftw_alloc_complex(alloc_size);
    out_data = fftw_alloc_complex(alloc_size);
    plan = fftw_mpi_plan_dft_1d(local_size, in_data, out_data, MPI_COMM_WORLD, FFTW_FORWARD, FFTW_ESTIMATE);
    for(int i = 0; i < local_size; ++i){
        in_data[i][0]= rand_double();
        in_data[i][1] = 0;
    }
    if (rank == 0) {
        time_start = MPI_Wtime();
    }
    fftw_execute(plan);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        time_end = MPI_Wtime();
        printf("%d\t%d\t%f\n", total_size, size,time_end - time_start);
    }
    fftw_destroy_plan(plan);

    /* get local data size and allocate */
    MPI_Finalize();
}
