#include <iostream>
using namespace std;

template<typename T> 
T f(T n) { 
    return n; 
}

double f(double n) { 
    return n; 
}
 
int main()
{
    int (*p)(int) = f; // instantiates and selects f<int>
    cout << p(1) << endl;
    double (*q)(double) = f; // instantiates and selects f<int>
    cout << q(1.2) << endl;
    return 0;
}
