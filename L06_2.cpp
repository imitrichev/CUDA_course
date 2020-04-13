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
// just explicitly name it shared (without it - the same sense)
#pragma omp parallel num_threads(3) shared(n)
{
// one-line critical to update shared variable
		#pragma omp atomic
			n++;
}

cout<<"n= "<<n<<endl;

return 0;
}
