#include <thread>
#include <iostream>
void threadCallback(int * x)
{
    (*x)++;
    std::cout<<"Inside Thread x = "<<*x<<std::endl;
}
int main()
{
    int x = 9;
    std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
    std::thread threadObj(threadCallback,(&x));
    threadObj.join();
    std::cout<<"In Main Thread : After Thread Joins x = "<<x<<std::endl;
    return 0;
}