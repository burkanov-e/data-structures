#include <iostream>

int main()
{
#ifdef AUCA_DEBUG
   std::cout << "Author: Burkanov Esenbek" << std::endl;
#endif
    std::cout << "Hello, C++ " <<__cplusplus << " !!!\n";
}

