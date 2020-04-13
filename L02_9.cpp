// лямбда функция

#include <algorithm>
#include <vector>
#include <iostream>
int main() {
std::vector<int> v = {1, 2, 3, 4}; // С++11 
// vector construct from initializer list
std::for_each(v.begin(), v.end(), [](int a) { std::cout<<a<<std::endl; });
}
