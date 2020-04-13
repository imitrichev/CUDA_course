#include "mpi.h"
#define N 1

using namespace std;

// run with:
// mpic++ l09_02.cpp && mpirun -n 4 ./a.out

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm comm=MPI_COMM_WORLD;
    int num_proc, *sendarray;
    int root=0, myrank, *rbuf;

    MPI_Comm_rank(comm, &myrank);

    if (myrank == root) {
       MPI_Comm_size(comm, &num_proc);
       sendarray = new int[num_proc*N];
       for (int i=0; i<num_proc*N; i++)
		sendarray[i]=i;
    }
	rbuf = new int [N];

    MPI_Scatter(sendarray, N, MPI_INT, rbuf, N, MPI_INT, root, comm);

	for (int i=0; i<N; i++)
		cout << myrank << " prints " << rbuf[i] << " " << endl;

	if (myrank == root)
		delete [] sendarray;
	else
		delete [] rbuf;
    MPI_Finalize();
    return 0;
}