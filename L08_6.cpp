#include "mpi.h"
#define N 1

using namespace std;

// run with:
// mpic++ l09_02.cpp && mpirun -n 4 ./a.out

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm comm=MPI_COMM_WORLD;
    int num_proc, sendarray[N];
    for (int i=0; i<N; i++)
	sendarray[i]=2;
    int root=0, myrank, *rbuf;

    MPI_Comm_rank(comm, &myrank);
    if (myrank == root) {
       MPI_Comm_size(comm, &num_proc);
       rbuf = new int[num_proc*N];
    }

    MPI_Gather(sendarray, N, MPI_INT, rbuf, N, MPI_INT, root, comm);

    if (myrank == root)
    {
	for (int i=0; i<num_proc*N; i++)
		cout << rbuf[i] << " " << endl;
	delete [] rbuf;
    }
    MPI_Finalize();
    return 0;
}