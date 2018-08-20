#include <iostream>
using namespace std;

int main() {
//pc is a non-const pointer to const int
// cpc is a const pointer to const int
// ppc is a non-const pointer to non-const pointer to const int
const int ci = 10, *pc = &ci, *const cpc = pc, **ppc;
// p is a non-const pointer to non-const int
// cp is a const pointer to non-const int
int i, *p, *const cp = &i;
  
i = ci;    // okay: value of const int copied into non-const int
*cp = ci;  // okay: non-const int (pointed-to by const pointer) can be changed
pc++;      // okay: non-const pointer (to const int) can be changed
pc = cpc;  // okay: non-const pointer (to const int) can be changed
pc = p;    // okay: non-const pointer (to const int) can be changed
ppc = &pc; // okay: address of pointer to const int is pointer to pointer to const int
  
//   ci = 1;    // error: const int cannot be changed
//   ci++;      // error: const int cannot be changed
//   *pc = 2;   // error: pointed-to const int cannot be changed
//   cp = &ci;  // error: const pointer (to non-const int) cannot be changed
//   cpc++;     // error: const pointer (to const int) cannot be changed
//   p = pc;    // error: pointer to non-const int cannot point to const int
//   ppc = &p;  // error: pointer to pointer to const int cannot point to
                // pointer to non-const int
return 0;
}
