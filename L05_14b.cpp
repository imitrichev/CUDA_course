#include <iostream>       // std::cout
#include <omp.h>
using namespace std;

int main()
{
	int n;

	#pragma omp parallel num_threads(3) private (n)
	{
		n=omp_get_thread_num()+1;
		cout <<n<<endl;
		#pragma omp barrier
		#pragma omp single copyprivate(n)
			n=100;
		cout <<n<<endl;
	}

	return 0;
}
