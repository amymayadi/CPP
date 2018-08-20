#include <iostream>
 
using namespace std;
 
 
int main() {
    int y = 2;
    int &x = y;
    y = y + 1;
    cout << "y: " << y << " x: " << x << endl;
    x = x + 1; 
    cout << "y: " << y << " x: " << x << endl;
    return 0;
}
