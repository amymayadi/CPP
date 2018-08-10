#include <iostream>

int main()
{
    const int a = 5;
    //int &b = a;  // 编译错误，不允许指向const变量。
    int &b = const_cast<int&>(a);
    std::cout << "&a=" << &a << std::endl;
    std::cout << "&b=" << &b << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    b = 19;
    std::cout << "&a=" << &a << std::endl;
    std::cout << "&b=" << &b << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "*(&a)=" << *(&a) << std::endl;
    int c = a;
    std::cout << "&c=" << &c << std::endl;
    std::cout << "c=" << c << std::endl;
    c = b;
    std::cout << "&c=" << &c << std::endl;
    std::cout << "c=" << c << std::endl;
    int *p = & const_cast<int&>(a);
    std::cout << "*p=" << *p << std::endl;
    std::cout << "p=" << p << std::endl;
    // p = &a;  // 编译错误，invalid conversion from ‘const int*’ to ‘int*’
    // std::cout << "*p=" << *p << std::endl;
    // std::cout << "p=" << p << std::endl;
    return 0;
}
