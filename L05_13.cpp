#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int tid=777;

	#pragma omp parallel num_threads(3)
	{
		tid=omp_get_thread_num();
		cout <<tid<<endl;
		#pragma omp single nowait
		// prints 8 from master thread 0
			cout<<"single:" << tid << endl;
	}

	return 0;
}
