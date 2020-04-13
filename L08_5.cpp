#include "mpi.h"
#define N 300

using namespace std;

int main(int argc, char **argv)
{
	double x[N], sum_x, sum_p;
	int myrank, p;
	MPI_Status status; MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, & p);
	// let's fill array only for process 0
	if (myrank == 0)
	for (int i = 0; i < N; i++)
		x[i] = 1;
	MPI_Bcast (x, N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	int k = N / p;
	int i1 = k * myrank;
	int i2 = k * (myrank + 1); 
	if (myrank == p - 1)
		i2 = N;
	for ( int i = i1; i < i2; i++ )
		sum_p += x[i];
	cout << " My x " << sum_p << endl;
	if (myrank == 0 )
	{
		sum_x = sum_p;
		for ( int i = 1; i < p; i++ )
		{
			MPI_Recv(&sum_p, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
			sum_x += sum_p;
		}
	}
	else
		MPI_Send(&sum_p, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	if ( myrank == 0 ) cout << " Summa x " << sum_x << endl;
	MPI_Finalize();
	return 0;
}