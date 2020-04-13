#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int main()
{
//measure execution time
	int nthreads, tid;
	double time=999;
	#pragma omp parallel num_threads(3) firstprivate(time)
	{
		cout<< "time variable " << time << endl;
	}
	return 0;
}
