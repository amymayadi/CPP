#include <iostream>

int main()
{
    const int a = 5;
    //int &b = a;  // 编译错误，不允许指向const变量。
    // 这是一个undefined behavior，const_cast应使用于，预知为非const的变量而不是const变量，通常用于常量指针或常量引用的去常量
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
