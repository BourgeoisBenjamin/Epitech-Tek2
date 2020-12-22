#include "library.h"

#include <iostream>

lib2::lib2() : _name("LIB2")
{
}

lib2::~lib2()
{
}

void lib2::init()
{
    std::cout << "[LIB 2] Init..." << std::endl;
}

void lib2::stop()
{
    std::cout << "[LIB 2] Stop..." << std::endl;
}

const std::string &lib2::getName() const
{
    return _name;
}

extern "C"
{
lib2 *make_lib2()
{
    return new lib2();
}
}