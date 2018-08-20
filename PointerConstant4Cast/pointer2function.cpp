#include <iostream>
using namespace std;
int f(int n)
{
    std::cout << n << '\n';
    return n * n;
}
 
int main()
{
    int (*p)(int) = f;
    int x = p(7);
}
