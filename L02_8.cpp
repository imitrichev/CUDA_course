// выполнение одной операции на рядом объектов без лямбды.
// используется функтор
#include <algorithm>
#include <vector>
#include <iostream>
 struct my_str {
    void operator()(int a) {
      std::cout<<a<<std::endl;
    }
  };
int main() {
std::vector<int> v = {1, 2, 3, 4}; // С++11 
// vector construct from initializer list
my_str f;
std::for_each(v.begin(), v.end(), f);
}