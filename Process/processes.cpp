#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    fork();
    std::cout << "Hello World! " << getpid() << std::endl;
    return 0;
}