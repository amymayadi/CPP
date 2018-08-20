#include <iostream>
using namespace std;
int f(int n)
{
    std::cout << n << '\n';
    return n * n;
}
 
int main()
{
    //int f(int);
    int (*p)(int) = f;  // pointer p is pointing to f
    int (&r)(int) = *p; // the lvalue that identifies f is bound to a reference
    r(2);               // function f invoked through lvalue reference
    (*p)(3);            // function f invoked through the function lvalue
    p(4);               // function f invoked directly through the pointer
    return 0;
}
