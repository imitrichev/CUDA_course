#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int n=999;

int main()
{
	omp_set_num_threads(2);
	#pragma omp threadprivate(n)

	#pragma omp parallel
	{
		cout<< "before n= " << n << endl;
		n=omp_get_thread_num();
		cout<< "after n= " << n << endl;
	}
	// reset to 0
	cout<<" MIDDLE n = "<<n<<endl;
	#pragma omp parallel
	{
		cout<< "n= " << n << endl;
	}

	return 0;
}
