#include<iostream>
using namespace std;

class A {
public:
    A() {
        password = 1111;
        birthday = 808;
    }

    ~A() { }

    friend int func(A a); // 向c++表示，int func(A a)是我的朋友，所以它可以使用我的所有东西。
    friend class B;       // 向c++表示，class B是我的朋友，所以它可以使用我的所有东西。

private:
    int password;
    int birthday;
};

int func(A a) {
    cout << a.password << " and " << a.birthday << endl; //可以访问
    a.password = 1;                                      //甚至可以修改
    cout << a.password << endl;
    return 0;
}

class B {
public:
    B() { }

    ~B() { }
    // 因为在A类中已经声明了B类是它的朋友，所以B类中方法就可以访问A类的私有变量了
    void show(A a) {
        cout << "your birthday is " << a.birthday << " and with pass: " << a.password << endl;
    }

private:
};

int main() {

    A a;

    func(a);

    B b;

    b.show(a);

    return 0;
}
