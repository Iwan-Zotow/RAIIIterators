#include <iostream>
#include <fstream>
#include <iomanip>

#include "Iterator.hpp"

int main(int argc, char* argv[])
{
    int test[] {1, 2, 3, 4, 5};
    
    Iterator i(test);
    
    auto a = ++i;
    
    auto b = i++;
    
    ++i;
    
    std::cout << *a << " " << *b << " " << *i << std::endl;

    return 0;
}
