#include <algorithm>
#include <vector>
#include <iostream>
int main() {
std::vector<int> v = {1, 2, 3, 4};
int b=9;
std::for_each(v.begin(), v.end(), [](int a) { std::cout<<a+b<<std::endl; });
}
