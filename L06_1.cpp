#include <iostream>       // std::cout
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
srand(time(NULL));
int n;
#pragma omp parallel num_threads(3)
{
	#pragma omp for lastprivate(n)
		for (n=0; n<10; n++)
		#pragma omp critical
		{
			cout<<n<<" ";
			cout<<omp_get_thread_num()<<" "<<n<<endl;
		}

// gives 10
	cout<<"Parallel area:"<<n<<endl;
}

return 0;
}
