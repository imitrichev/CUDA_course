// compile with
// g++ -std=c++11 -pthread file_name.cpp

#include <iostream>
#include <thread>

void function_to_call(int _id)
{
	std::cout << "Launched by thread " << _id << std::endl;
}

int main()
{
	const int num_threads = 10;
	std::thread threads(num_threads);
	for (int i = 0; i < num_threads; ++i)
	{
		threads[i] = std:thread(function_to_call, i);
	}

	for (int i = 0; i < num_threads; ++i)
	{
		threads[i].join;
	}
	return 0;
}
