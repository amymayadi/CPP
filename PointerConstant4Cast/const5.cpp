#include <stdio.h>
#include <iostream>
using namespace std;
 
//c++中的引用实例
void fun(int &x){
    printf("fun(int& x)形式参数x的值为：%d\n",x);
    printf("形式参数的地址为：%d\n",&x);
    x+=10;
}
void fun2(int *y){
    printf("fun2(int* num)形式参数y指向变量的值为：%d\n",*y);
    printf("形式参数y的值为：%d\n",y); 
    printf("形式参数y的地址为：%d\n",&y);  
    *y =(*y)+10;
}
 
int main(void){
    int num = 4,a=3;
 
    printf("实参num的值为：%d\n",num);
    printf("实参num的地址为：%d\n",&num);//都是一样的
    fun(num);
    cout<<"fun函数后num的值为："<<num<<endl; //14 num的值改啦
 
    fun2(&a);
    printf("fun2函数后实参a的值为：%d\n",a);
    printf("实参a的地址为：%d\n",&a);//
    return 0;
}
