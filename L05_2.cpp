#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int main()
{
//measure execution time
	int nthreads, tid, is_parallel=1;
	double time;
	#pragma omp parallel if (is_parallel==1) private(time,tid)
	{
		tid = omp_get_thread_num();
		time = omp_get_wtime();
		cout << "Thread:" << tid << endl;
		cout<< omp_get_wtime()-time << endl;
	}
	return 0;
}
