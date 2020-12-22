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

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" "
    "senorita" << std::endl;
    return true;
}