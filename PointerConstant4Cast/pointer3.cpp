#include <iostream>
 
using namespace std;
 
 
int main() {
   long arr[] = {6, 0, 9, 6};
 
   long *ptr = arr;
   cout << arr << endl; //输出的是地址信息， 想想在《C++ strings》中， 输出的是整个string， 
   cout << arr[0] << endl;
   cout << *ptr << endl;
   cout << "One long integer need: " << sizeof(long) << " bytes "<<endl;
   cout << "The position of the array: " << ptr << endl;
   ptr++;
   cout << "After increment 1, the position of ptr: " << ptr <<endl;
   cout << "The value ptr points to: " << *ptr << endl;
   return 0;
}
