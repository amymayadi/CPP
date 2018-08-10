
#include <iostream>
 
using namespace std;
 
 
int *myFunc() {
   int phantom = 4;
 
   return &phantom;
}
int main() {
   int* ptr = myFunc();
 
   cout << *ptr<< endl; // &phantom has been already deallocated.
   return 0;
}
