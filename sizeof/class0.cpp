#include <iostream>
using namespace std;
class C
{
};

int main()
{
    C c1;
    size_t n = sizeof(c1);
    cout << "class c = " << n << endl;
    char ch = 'c';
    n = sizeof(ch);
    cout << "char = " << n << endl;
    int a;// = 1;
    n = sizeof(a);
    cout << "int = " << n << endl;
    unsigned u = 1;
    n = sizeof(u);
    cout << "unsigned int= " << n << endl;
    // long int（简写：long），有符号整数
    long b = 1;
    n = sizeof(b);
    cout << "long = " << n << endl;
    // 32bit系统中 long int为32bit，64bit系统中 long int为64bit
    long int li = 1;
    n = sizeof(li);
    cout << "long int = " << n << endl;
    string str = (n==4)?"32bit":"64bit";
    cout << str << endl;
    unsigned long ul = 1;
    n = sizeof(ul);
    cout << "unsigned long = " << n << endl;
    size_t s = 1;
    n = sizeof(s);
    cout << "size_t = " << n << endl;
    return 0;
}
