#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    string str = argv[1];
//    string str1 = *argv[1];
    string ss = str + ":hello";
    cout << ss <<endl;
    return 0;
} 
