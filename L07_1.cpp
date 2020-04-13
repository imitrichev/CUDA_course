// основан на примере из учебника "Технологии параллельного программирования MPI и OpenMP" Антонова А.С.
#include "mpi.h"
#include <stdio.h>
int main(int argc, char **argv)
{
   int rank;
   float a, b;
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   a = 90.0;
   b = 65.0;
   if(rank == 0)
   {
      MPI_Send(&b, 1, MPI_FLOAT, 1, 5, MPI_COMM_WORLD);
      MPI_Recv(&a, 1, MPI_FLOAT, 1, 5, MPI_COMM_WORLD, &status);
   }
   if(rank == 1)
   {
      MPI_Recv(&b, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD, &status);
      MPI_Send(&a, 1, MPI_FLOAT, 0, 5, MPI_COMM_WORLD);
   }
   printf("process %d a = %f, b = %f\n", rank, a, b);
   MPI_Finalize();
   return 0;
}
