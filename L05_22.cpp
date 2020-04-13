#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int A[20],B[20],C[20], i,n;
	for (i=0;i<20;i++)
	{
		A[i]=i; B[i]=2*i;C[i]=11110;
	}
	#pragma omp parallel shared (A,B,C) private (i,n) num_threads(2)
	{
		n = omp_get_thread_num();
	// on my PC is equivalent to dynamic scheduling (last chunk size is
	// not fixed)
		#pragma omp for schedule (guided)
		for (i=0;i<20;i++)
		{
			C[i]=A[i]+B[i];
			#pragma omp critical
			cout<<i<<" by "<<n<<endl;
		}
	}
	return 0;
}
