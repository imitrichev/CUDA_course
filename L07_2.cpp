#include "mpi.h"
#include <stdio.h>

//cat /proc/cpuinfo
//to calculate number of cores
using namespace std;

int main(int argc, char **argv) {
int rank, size, prev, next;
int buf[1];
MPI_Request reqs[2];
MPI_Status stats[2];
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
prev=((rank-1>=0)?rank-1:size-1);
next=((rank+1<size)?rank+1:0);
MPI_Irecv(&buf[0], 1, MPI_INT, prev, 5, MPI_COMM_WORLD, &reqs[0]);
MPI_Isend(&rank, 1, MPI_INT, next, 5, MPI_COMM_WORLD, &reqs[1]);
MPI_Waitall(2, reqs, stats);
cout << " process " << rank << " received from " <<buf[0] << endl;
MPI_Finalize();
return 0;
}
