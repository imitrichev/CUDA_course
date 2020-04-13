#include "mpi.h"

using namespace std;
#define N 10000000
#define NTIMES 100
static double a = 0.;
static double b = 1.;
static double INTEGRAL = 0.;

void proc_integral(double (*fun)(double), const int myrank, int p)
{
	double h_p = (b - a) / p;
	double a_p = a + myrank * h_p;
	double integ = 0.;
	int n_p = N / p;
	int i;
	double b_p = a_p + h_p;
	double x_p = a_p;

	// compute part of integral on interval from a_p to b_p
	while (x_p < b_p) {
		integ += fun(x_p) * h_p / n_p;  x_p += h_p / n_p;
	}
	MPI_Reduce(&integ, &INTEGRAL, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
}

double f(double x) { return x*x; }

int main(int argc, char **argv)
{
	double time_start, time_finish;
	int myrank;
	int p;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	time_start = MPI_Wtime();
	proc_integral(f, myrank, p);
	time_finish = MPI_Wtime();
	
	cout << " Process " << myrank << " time = " << (time_finish-time_start)/NTIMES << endl;
	if (myrank == 0)
		cout << " Integral " << INTEGRAL << endl;
	MPI_Finalize();
	return 0;
}
