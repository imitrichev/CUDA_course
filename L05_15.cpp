#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int n;
	omp_set_num_threads(2);

	#pragma omp parallel num_threads(3) private (n)
	{
		n=omp_get_thread_num()+1;
		cout <<n<<endl;
		#pragma omp master
			n=100;
		cout <<n<<endl;
	}

	return 0;
}
