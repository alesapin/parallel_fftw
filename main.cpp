#include <mpi.h>
#include "fftw3.h"
#include "fftw3-mpi.h"
#include <iostream>
#include <random>
#include "cxxopts.hpp"

std::ostream& operator<<(std::ostream& os, fftw_complex num){
  return os << "(" << num[0] << ", "<< num[1] << "i)";
}



int main(int argc, char **argv)
{
  cxxopts::Options options("FFTW Mpi test.", "Simple test of performance.");
  options.add_options()
    ("s,size", "Size of input", cxxopts::value<long>());
  options.parse(argc, argv);
  ptrdiff_t total_size = options["size"].as<long>();
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<> dist(0.0, 1.0);

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
    in_data[i][0]= dist(mt);
    in_data[i][1] = 0;
  }
  if(rank == 0){
    time_start = MPI_Wtime();
  }
  fftw_execute(plan);
  MPI_Barrier(MPI_COMM_WORLD);
  if (rank == 0) {
    time_end = MPI_Wtime();
    std::cout << time_end - time_start << "\n";
  }
  fftw_destroy_plan(plan);

  /* get local data size and allocate */
  MPI_Finalize();
}
