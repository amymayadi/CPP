#include<iostream>  
using namespace std;  
  
class Base  
{  
public:   
    virtual void f(float x)  
    {  
        cout<<"BASE::f"<<x<<endl;  
    }  
    virtual void g(float x)  
    {  
        cout<<"BASE::g"<<x<<endl;  
    }  
    void h(float x)  
    {  
        cout<<"BASE::h"<<x<<endl;  
    }  
};  
class Driver:public Base  
{  
public:   
    void f(float x)  
    {  
        cout<<"d::f"<<x<<endl;  
    }  
    virtual void g(int x)  
    {  
        cout<<"d::g"<<x<<endl;  
    }  
    void h(float x)  
    {  
  
        cout<<"d::h"<<x<<endl;  
    }  
};  
  
int main(int argc, char const *argv[])  
{  
    Driver d;  
    Base* pb=&d;  
    Driver* pd=&d;  
    cout<<"pd->f(1.2f)"<<endl;  
    pd->f(1.2f);
    cout<<"pb->f(1.2f)"<<endl;  
    pb->f(1.2f);
    cout<<"pd->Base::g(1.2f)"<<endl;
    pd->Base::g(1.2f);
    cout<<"pd->g(1.2f)"<<endl;  
    pd->g(1.2f);
    cout<<"pb->g(1.2f)"<<endl;  
    pb->g(1.2f);
    cout<<"pd->h(1.2f)"<<endl;  
    pd->h(1.2f);
    cout<<"pb->h(1.2f)"<<endl;  
    pb->h(1.2f);  
    return 0;  
  
}
