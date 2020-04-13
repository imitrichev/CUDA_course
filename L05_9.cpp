#include <iostream>       // std::cout
#include <omp.h>
using namespace std;
int n=999;
// set before thread private - spread to all threads

int main()
{
	omp_set_num_threads(2);
	#pragma omp threadprivate(n)

	#pragma omp parallel copyin(n)
	{
		cout<< "n= " << n << endl;
	}

	return 0;
}
