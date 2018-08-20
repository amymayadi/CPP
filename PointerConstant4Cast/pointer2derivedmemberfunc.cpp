#include <iostream>
using namespace std;

struct Base {};
struct Derived : Base
{
    void f(int n) { std::cout << n << '\n'; }
};
 
int main()
{
    void (Derived::* dp)(int) = &Derived::f;
    void (Base::* bp)(int) = static_cast<void (Base::*)(int)>(dp);
 
    Derived d;
    (d.*bp)(1); // okay: prints 1
 
    Base b;
    (b.*bp)(2); // undefined behavior
    return 0;
}
