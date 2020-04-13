#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int tid;

	omp_set_nested(1);
	#pragma omp parallel num_threads(3) private (tid)
	{
		tid = omp_get_thread_num();
//produces 15 threads
		#pragma omp parallel num_threads(5)
		{
// critical section - one-by-one execution
		#pragma omp critical
			cout<<tid<<"=> new "<<omp_get_thread_num()<<endl;
		}
	}


	return 0;
}
