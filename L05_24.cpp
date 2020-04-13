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
#pragma omp parallel num_threads(3) private (n)
{
	n = omp_get_thread_num();
	#pragma omp sections
	{
	#pragma omp section
	{
		cout<<"First thread:"<<n<<endl;

	}
	#pragma omp section
	{
		sleep(2);
		cout<<"Second thread:"<<n<<endl;
	}
	#pragma omp section
	{
		sleep(rand()%5+3);
		cout<<"Third thread:"<<n<<endl;
	}
	}
	cout<<"Parallel area:"<<n<<endl;
	}

return 0;
}
