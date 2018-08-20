#include <iostream>
using namespace std;

struct Base {
    void f(int n) {cout << n << endl;}
};

struct Derived : Base {

};

int main() {
    void (Base::* bp)(int) = &Base::f; // !!!注意这里不是Base::f(),函数名为地址
    void (Derived::* dp)(int) = bp;
    Derived d;
    (d.*dp)(1);
    (d.*bp)(2);
    return 0;
}
