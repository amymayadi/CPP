#include<iostream>
using namespace std;

class A {
public:
    A() {
        password = 1111;
        account = 808;
    }

    ~A() { }

    friend ostream& operator << (ostream &os , A a);

private:
    int password;
    int account;
};

ostream& operator << (ostream &os , A a) {
    os << "your account is " << a.account << " and with pass: " << a.password << endl;
    return os;
}

int main() {

    A a;

    cout << a;

    return 0;
}
