#include <iostream>
using namespace std;

struct Base {};
struct Derived : Base { int m; };
 
int main()
{
    int Derived::* dp = &Derived::m;
    int Base::* bp = static_cast<int Base::*>(dp);
 
    Derived d;
    d.m = 7;
    std::cout << d.*bp << '\n'; // okay: prints 7
 
    Base b;
    //std::cout << b.*bp << '\n'; // undefined behavior
}
