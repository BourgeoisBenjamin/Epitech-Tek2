/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "Woody.hpp"
#include <ostream>

Woody::Woody(const std::string &name, const std::string &filename) : Toy
(WOODY, name, filename)
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << _name << " \"" << statement << "\"" << std::endl;
    return true;
}