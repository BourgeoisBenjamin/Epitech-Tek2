#include "library.h"

#include <iostream>

extern "C"
{
    void constructor_ft() {
        std::cout << "[libgra] Loading gra library..." << std::endl;
    }
}

extern "C"
{
    void destructor_ft() {
        std::cout << "[libgra] Closing gra library..." << std::endl;
    }
}

extern "C"
{
    void entryPoint_ft() {
        std::cout << "[libgra] Entry Point for gra library..." << std::endl;
    }
}
