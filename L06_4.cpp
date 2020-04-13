#include <iostream>       // std::cout
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

omp_lock_t lock;
int main()
{
	int n;
	omp_init_lock(&lock);
	double s=omp_get_wtime();
	#pragma omp parallel private (n) num_threads(3)
	{
		n = omp_get_thread_num();
		omp_test_lock(&lock);
		sleep(1);
		omp_unset_lock(&lock);
	}
	omp_destroy_lock(&lock);
// time spent will be 1 seconds due to non-blocking lock
	cout<<omp_get_wtime()-s<<endl;

return 0;
}
