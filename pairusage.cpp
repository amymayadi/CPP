#include <iostream>
using namespace std;

class Ai
{
public:
Ai(int x, string y){
a1 = x;
a2 = y; 
}

int a1;
string a2;
};

class Bi
{
public:
Bi(int x, string y){
b1 = x;
b2 = y; 
}

int b1;
string b2;
};

bool func(pair<Ai, Bi> *p)
{
    Ai ta(5, "tmp");
    Bi tb(6, "test");
    p->first = ta;
    p->second = tb;
}

int main()
{
    pair<int, int> a(1,2);
    cout << a.first << a.second << endl;
    Ai ai(1, "stra1");
    Bi bi(5, "strb1");
    pair<Ai, Bi> ma(ai, bi);
    cout << ma.first.a1 << ma.first.a2 <<endl;
    cout << ma.second.b1 << ma.second.b2 << endl;
    pair<Ai, Bi>*p = &ma;
    //p = &ma;
    cout << p->first.a1 << p->first.a2 <<endl;
    cout << p->second.b1 << p->second.b2 << endl;

    return 0;
}
