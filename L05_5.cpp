#include <iostream>       // std::cout
#include <omp.h>
#include <unistd.h>
using namespace std;
int main()
{
//measure execution time
	int nthreads, tid;
	double time;
	#pragma omp parallel num_threads(10) reduction(+:time)
	{
		cout<< "What do you think the time is? -> " <<time<<endl;
		time = omp_get_wtime();
		sleep(1);
		time=omp_get_wtime()-time;
		cout<< "wall time for thread " << time << endl;
	}
	cout << "Total cpu time for all threads " << time << endl;
	return 0;
}
