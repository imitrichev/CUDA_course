#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int n=111;

int main()
{
	omp_set_num_threads(2);
	#pragma omp threadprivate(n)
// this is set only for thread 0
	n=999;

	#pragma omp parallel
	{
		cout<< "n= " << n << endl;
	}

	return 0;
}
