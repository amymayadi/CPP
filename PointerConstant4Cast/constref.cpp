#include <stdio.h>
#include <iostream>
using namespace std;
void test_const();
 
int main(void){
 
    test_const();
    return 0;
}
 
void test_const(){
    int a=1;
    int &b=a;
    b=2;
    cout<<"a="<<a<<endl;//2
    int c=1;
    const int &d=c;
//  d=2;//编译错误 error: assignment of read_only reference 'd'
    c=2;//正确
    cout<<"c="<<c<<endl;
    const_cast<int&>(d) = 5;
    cout<<"c="<<c<<endl;
    int& w = const_cast<int&>(d);
    w = 19;
    cout<<"c="<<c<<endl;
}
