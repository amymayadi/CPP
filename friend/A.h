//A.h  
#pragma once  
#include <iostream>  
using namespace std;  
class A  
{  
    friend class B;  //如果不写这句话将会出现编译错误
public:  
    ~A(void);  
    A();
private:    
    int m_nItem;
};
