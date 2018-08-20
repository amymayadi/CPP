#include <iostream>
using namespace std;

struct C { int m; };
 
int main()
{
    int C::* p = &C::m;          // !!!pointer to data member m of class C

    C c = {7};
    std::cout << c.*p << '\n';   // prints 7

    C* cp = &c;
    cp->m = 10;
    std::cout << cp->*p << '\n'; // prints 10
    return 0;
}
