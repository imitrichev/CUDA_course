#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int A[20],B[20],C[20],i,j,n;
	for (i=0;i<20;i++)
	{
		A[i]=i; B[i]=2*i;
	}
	#pragma omp parallel shared (A,B,C) private (i,j,n) num_threads(10)
	{
		n = omp_get_thread_num();
	// on my PC 3 - chunk size by default
		#pragma omp for schedule (static,1) //collapse(2)
		for (j=0;j<2;j++)
		for (i=0;i<10;i++)
		{
			C[j*10+i]=A[j*10+i]+B[j*10+i];
			#pragma omp critical
			cout<<i<<" (C) by "<<n<<endl;
		}
	}
return 0;
}
