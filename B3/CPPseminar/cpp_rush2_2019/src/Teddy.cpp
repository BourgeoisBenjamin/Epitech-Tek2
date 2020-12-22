/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Teddy.hpp"

#include "../include/Object.hpp"

Teddy::Teddy(const std::string &title) : Toy::Toy(title)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    if (!_isTaken) {
        _isTaken = true;
        std::cout << "gra hu" << std::endl;
    }
}