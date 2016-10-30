#include <mpi.h>
#include "fftw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

double rand_double() {
    return (double)rand()/(double)RAND_MAX;
}
double timedifference_msec(struct timeval t0, struct timeval t1) {
        return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int main(int argc, char **argv) {


    ptrdiff_t total_size = 1024;

    fftw_complex *in_data, *out_data;
    fftw_plan plan;
    for(;total_size < (ptrdiff_t)pow(2,30); total_size*=2) {
        in_data = fftw_alloc_complex(total_size);
        out_data = fftw_alloc_complex(total_size);
        plan = fftw_plan_dft_1d(total_size, in_data, out_data, FFTW_FORWARD, FFTW_ESTIMATE);
        for(int i = 0; i < total_size; ++i){
            in_data[i][0]= rand_double();
            in_data[i][1] = 0;
        }
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        fftw_execute(plan);
        gettimeofday(&stop, NULL);
        printf("%lu\t%f\n", total_size, timedifference_msec(start,stop)/1000);
        fftw_destroy_plan(plan);
        fftw_free(in_data); fftw_free(out_data);
    }
    /* get local data size and allocate */
}
