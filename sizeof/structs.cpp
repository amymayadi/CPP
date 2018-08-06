#include <iostream>
using namespace std;

struct c{char ca;int i;};

int main()
{
    c c1 = {'a', 0xFFFFFFFF};
    size_t n = sizeof(c1);
    cout << n << endl;
    return 0;
}
