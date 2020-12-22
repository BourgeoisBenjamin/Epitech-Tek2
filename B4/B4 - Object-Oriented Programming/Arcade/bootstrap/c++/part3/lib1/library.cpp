#include "library.h"

#include <iostream>

lib1::lib1() : _name("LIB1")
{
}

lib1::~lib1()
{
}

void lib1::init()
{
    std::cout << "[LIB 1] Init..." << std::endl;
}

void lib1::stop()
{
    std::cout << "[LIB 1] Stop..." << std::endl;
}

const std::string &lib1::getName() const
{
    return _name;
}

extern "C"
{
    lib1 *make_lib1()
    {
        return new lib1();
    }
}