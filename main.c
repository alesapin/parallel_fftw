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

    //fprintf(stderr, "Size %ld\n", total_size);
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    //fprintf(stderr, "Init Failed\n");
    fftw_mpi_init();

    ptrdiff_t local_start, local_size, dum1, dum2;
    double time_start, time_end;
    fftw_complex *in_data, *out_data;
    fftw_plan plan;
    fftw_complex *total_data;
    if(rank==0){
        total_data = fftw_alloc_complex(total_size);
        for(int i = 0; i < total_size; ++i){
            total_data[i][0] = rand_double();
            total_data[i][1] = 0;
        }
    }

    //fprintf(stderr, "Size Failed\n");
    ptrdiff_t alloc_size = fftw_mpi_local_size_1d(total_size, MPI_COMM_WORLD, FFTW_FORWARD , FFTW_ESTIMATE, &local_size, &local_start, &dum1, &dum2);

    //fprintf(stderr, "Alloc Failed\n");
    in_data = fftw_alloc_complex(alloc_size);
    out_data = fftw_alloc_complex(alloc_size);

    MPI_Scatter(total_data, alloc_size, MPI_COMPLEX, in_data, alloc_size, MPI_COMPLEX, 0, MPI_COMM_WORLD);
    //fprintf(stderr, "Plan Failed\n");
    plan = fftw_mpi_plan_dft_1d(local_size, in_data, out_data, MPI_COMM_WORLD, FFTW_FORWARD, FFTW_ESTIMATE);
    //fprintf(stderr, "Loop Failed\n");

    if (rank == 0) {
        time_start = MPI_Wtime();
    }
    //fprintf(stderr, "Execute Failed\n");
    fftw_execute(plan);
    MPI_Gather(out_data, alloc_size, MPI_COMPLEX, total_data, alloc_size, MPI_COMPLEX, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        time_end = MPI_Wtime();
        printf("%d\t%d\t%f\n", total_size, size,time_end - time_start);
    }

    //fprintf(stderr, "Destroy Failed\n");
    fftw_destroy_plan(plan);

    /* get local data size and allocate */
    MPI_Finalize();
}
