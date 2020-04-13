#include <algorithm>
#include <math.h>
#include <omp.h>
#include <iostream>
using namespace std;
#define eps 0.001

int main()
{
double start = omp_get_wtime();

int N = 1000;
int i,j;
int iter=0;
double ** grid = new double * [N+1];
double ** newgrid = new double * [N+1];

for (i=0;i<N+1;i++)
{
	grid[i] = new double[N+1];
	newgrid[i] = new double [N+1];
}

#pragma omp parallel shared(grid,newgrid) private (i,j)
{
    #pragma omp single
        cout<<"Num threads: "<<omp_get_num_threads()<<endl;
	#pragma omp for
	for (i=0;i<N+1;i++)
	{
		grid[i][0]=1;
		grid[0][i]=1;
		grid[N][i]=1;
		grid[i][N]=1;
		newgrid[i][0]=1;
		newgrid[0][i]=1;
		newgrid[N][i]=1;
		newgrid[i][N]=1;
	}

	#pragma omp for collapse(2)
	for (i=1;i<N;i++)
		for (j=1;j<N;j++)
			grid[i][j]=0;
}
		
double maxdiff=0;

do{
	#pragma omp parallel shared(grid,newgrid,maxdiff) private (i,j)
	{
		#pragma omp for collapse(2)
		for (i=1;i<N;i++)
			for (j=1;j<N;j++)
			{
				newgrid[i][j]= 0.25 * (grid[i-1][j]+grid[i+1][j]+grid[i][j-1]+grid[i][j+1]);
			}
		
		#pragma omp for collapse(2)
		for (i=1;i<N;i++)
			for (j=1;j<N;j++)
				grid[i][j]= 0.25 * (newgrid[i-1][j]+newgrid[i+1][j]+newgrid[i][j-1]+newgrid[i][j+1]);

		#pragma omp master
		{
			maxdiff=0;
			for (i=1;i<N;i++)
				for (j=1;j<N;j++)
					maxdiff = max(maxdiff,fabs(newgrid[i][j]-grid[i][j]));
		}
	}
	iter++;
}
while (maxdiff > eps);

cout<<"Iter:"<<iter<<endl;

/*for (i=0;i<N+1;i++)
{
	for (j=0;j<N+1;j++)
        cout<<grid[i][j]<<" ";
	cout<<endl;
}*/

for (i=0;i<N+1;i++)
{
	delete [] grid[i];
	delete [] newgrid[i];
}
delete grid;
delete newgrid;
double end = omp_get_wtime();
std::cout<<"Total time = "<<end-start<<endl;
return 0;
}