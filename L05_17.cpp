#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
int A[10], i;
#pragma omp parallel for shared (A) private (i)
	for (i=0; i<10; i++)
	{
		cout<<i<<" by "<<omp_get_thread_num()<<endl;
		A[i]=5;
	}
	return 0;
}