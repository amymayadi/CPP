#include <iostream>
using namespace std;

struct Base { int m; };
struct Derived : Base {};
 
int main()
{
    int Base::* bp = &Base::m;
    int Derived::* dp = bp;
    Derived d;
    d.m = 1;
    std::cout << d.*dp << ' ' << d.*bp << '\n'; // prints 1 1
}
