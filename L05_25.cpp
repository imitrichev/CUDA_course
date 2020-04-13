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
	#pragma omp sections lastprivate (n)
	{
	#pragma omp section
	{
		n=1;
		cout<<"First thread:"<<n<<endl;

	}
	#pragma omp section
	{
		n=2;
		cout<<"Second thread:"<<n<<endl;
	}
	#pragma omp section
	{
		n=3;
		cout<<"Third thread:"<<n<<endl;
	}
	}
	cout<<"Parallel area:"<<n<<endl;
}

return 0;
}
