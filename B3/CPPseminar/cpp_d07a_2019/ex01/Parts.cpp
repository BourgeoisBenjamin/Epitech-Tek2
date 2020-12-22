/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#include "Parts.hpp"

/* ARMS */

Arms::Arms(std::string serial, bool functionnal) : _serial(serial),
_functionnal(functionnal)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal() const
{
    return (_functionnal);
}

std::string Arms::serial() const
{
    return (_serial);
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " <<
    (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}

/* LEGS */

Legs::Legs(std::string serial, bool functionnal) : _serial(serial),
                                                   _functionnal(functionnal)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal() const
{
    return (_functionnal);
}

std::string Legs::serial() const
{
    return (_serial);
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " <<
              (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}

/* Head */

Head::Head(std::string serial, bool functionnal) : _serial(serial),
                                                   _functionnal(functionnal)
{
}

Head::~Head()
{
}

bool Head::isFunctionnal() const
{
    return (_functionnal);
}

std::string Head::serial() const
{
    return (_serial);
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " <<
              (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}