#include <iostream>
using namespace std;

struct A
{
    int m;
    // const pointer to non-const member
    int A::* const p;
};
 
int main()
{
    // non-const pointer to data member which is a const pointer to non-const member
    int A::* const A::* p1 = &A::p;
 
    const A a = {1, &A::m};
    std::cout << a.*(a.*p1) << '\n'; // prints 1
 
    // regular non-const pointer to a const pointer-to-member
    int A::* const* p2 = &a.p;
    std::cout << a.**p2 << '\n'; // prints 1
}
