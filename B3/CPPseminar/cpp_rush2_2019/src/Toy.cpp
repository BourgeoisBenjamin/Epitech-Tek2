/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Toy.hpp"

Toy::Toy(const std::string &title) : _title(title)
{
    _isTaken = false;
    _type = TOY;
}

Toy::~Toy()
{
}

void Toy::isTaken()
{
    if (!_isTaken) {
        _isTaken = true;
        std::cout << _title << " is taken" << std::endl;
    }
}

const std::string Toy::getTitle() const
{
    return _title;
}