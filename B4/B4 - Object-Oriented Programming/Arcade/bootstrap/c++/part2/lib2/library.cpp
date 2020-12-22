#include "library.h"

#include <iostream>

extern "C"
{
    void constructor_ft() {
        std::cout << "[libbar] Loading bar library..." << std::endl;
    }
}

extern "C"
{
    void destructor_ft() {
        std::cout << "[libbar] Closing bar library..." << std::endl;
    }
}

extern "C"
{
    void entryPoint_ft() {
        std::cout << "[libbar] Entry Point for bar library..." << std::endl;
    }
}
