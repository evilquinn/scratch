#include <iostream>
#include <fcntl.h>
#include <string.h>

void neg(int& n)
{
    n = ~n;
}

int main(int argc, char* argv[])
{

    int n = 12345;
    std::cout << "n:  " << n << std::endl;
    std::cout << "~n: " << ~n << std::endl;
    neg(n);
    std::cout << "~n: " << n << std::endl;


    std::cout << std::hex << std::showbase << 0xaabbccdd << std::endl;
    std::cout << "hello world" << std::endl;
}
