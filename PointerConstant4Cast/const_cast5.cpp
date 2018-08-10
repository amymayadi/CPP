#include <iostream>

struct SA{
    int i;
};

int main(){
    const SA ca={5};
    //ca.i = 10;  //直接修改const类型，编译错误
    SA &cb = const_cast<SA&>(ca); //cb与ca同一块内存

    SA *cp = NULL;
    //*cp = const_cast<SA&>(ca);
    //cp->i = 8;

    SA cq = const_cast<SA&>(ca);  //cq与ca不同内存，同样的内容
    cq.i = 9;
    cb.i = 10;
    return 0;
}
