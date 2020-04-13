#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int A[10],B[10],C[10], i,n;
	for (i=0;i<10;i++)
	{
		A[i]=i; B[i]=2*i;C[i]=0;
	}
	#pragma omp parallel shared (A,B,C) private (i,n)  num_threads(3)
	{
		n = omp_get_thread_num();
		#pragma omp for
		for (i=0;i<10;i++)
		{
			C[i]=A[i]+B[i];
			cout<<i<<" by "<<n<<endl;
		}
	}
	return 0;
}
