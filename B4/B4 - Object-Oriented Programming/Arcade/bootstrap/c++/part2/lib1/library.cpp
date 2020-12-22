#include "library.h"

#include <iostream>

extern "C"
{
    void constructor_ft() {
        std::cout << "[libfoo] Loading foo library..." << std::endl;
    }
}

extern "C"
{
    void destructor_ft() {
        std::cout << "[libfoo] Closing foo library..." << std::endl;
    }
}

extern "C"
{
    void entryPoint_ft() {
        std::cout << "[libfoo] Entry Point for foo library..." << std::endl;

    }
}