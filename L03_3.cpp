#include <thread>
#include <mutex>
#include <iostream>
struct Complex {
    std::mutex mutex;
    int i;

    Complex() : i(5) {}

    void mul(int x){
        std::lock_guard<std::mutex> lock(mutex);
        i *= x;
    }

    void div(int x){
        std::lock_guard<std::mutex> lock(mutex);
        i /= x;
    }
void both(int x, int y){
    std::lock_guard<std::mutex> lock(mutex);
    mul(x);
    div(y);
}
};

int main(){
    Complex complex;
    complex.both(4, 5);

    return 0;
}