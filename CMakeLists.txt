project(FFTW_MPI_PRG)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(FFTW_INCLUDE
    "${CMAKE_CURRENT_BINARY_DIR}/fftw/build/include"
)
set(FFTW_LIBS
    "${CMAKE_CURRENT_BINARY_DIR}/fftw/build/lib/libfftw3_mpi.a"
    "${CMAKE_CURRENT_BINARY_DIR}/fftw/build/lib/libfftw3.a"
)
set(CXXOPTS_INCLUDE
  "${CMAKE_CURRENT_SOURCE_DIR}/cxxopts"
)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

add_custom_command(
    OUTPUT ${FFTW_INCLUDE} ${FFTW_LIBS}
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/fftw"
    COMMAND mkdir -p build
    COMMAND ./configure MPICC=mpicc --enable-mpi --prefix=${CMAKE_CURRENT_BINARY_DIR}/fftw/build
    COMMAND make
    COMMAND make install
    VERBATIM
)
add_custom_target(FFTW_BUILD ALL DEPENDS ${FFTW_INCLUDE})

find_package(MPI REQUIRED)
include_directories(${FFTW_INCLUDE})
include_directories(${CXXOPTS_INCLUDE})
include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_C_COMPILER "mpic++")
add_executable( FFTW_MPI main.cpp )
add_dependencies(FFTW_MPI FFTW_BUILD)
target_link_libraries(FFTW_MPI ${MPI_C_LIBRARIES} ${MPI_CXX_LIBRARIES} ${FFTW_LIBS} m)
