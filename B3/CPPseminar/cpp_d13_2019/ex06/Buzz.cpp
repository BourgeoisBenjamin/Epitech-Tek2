/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "Buzz.hpp"
#include <ostream>

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ,
    name, filename)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" "
    "senorita" << std::endl;
    return true;
}