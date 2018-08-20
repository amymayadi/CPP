#include <iostream>
struct C {
   int x, y;
} c;
 
int main() {
c.x = 5;
c.y = 19;
int* px = &c.x;   // value of px is "pointer to c.x"
int* pxe= px + 1; // value of pxe is "pointer past the end of c.x"
int* py = &c.y;   // value of py is "pointer to c.y"
 
if(pxe == py)     // == tests if two pointers represent the same address
    std::cout << "pxe == py" << std::endl;  // may or may not fire
else
    std::cout << "pxe != py" << std::endl;                     
*pxe = 1; // !!! undefined behavior even if the assertion does not fire !!!
return 0;
}
