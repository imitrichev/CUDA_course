#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int main()
{
	int nthreads, tid;
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		cout << "Thread:" << tid << endl;
		if (tid == 0) {
			nthreads = omp_get_num_threads();
			cout << "Master:" << nthreads << endl;
		}
	}
	return 0;
}
