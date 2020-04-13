#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int n=111;

int main()
{
	omp_set_num_threads(2);
	#pragma omp threadprivate(n)
	n=999;

// this (copyin) updates n with value form thread 0
	#pragma omp parallel copyin(n)
	{
		cout<< "n= " << n << endl;
	}

	return 0;
}
