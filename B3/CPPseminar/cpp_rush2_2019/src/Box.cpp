/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Box.hpp"

Box::Box() : Wrap()
{
    _open = false;
    _type = BOX;
    std::cout << "A box is created" << std::endl;
}

Box::~Box()
{
    std::cout << "A box is destroyed" << std::endl;
}

void Box::closeMe()
{
    if (!_open) {
        std::cout << "The box is already closed" << std::endl;
    } else {
        _open = false;
        std::cout << "The box is now closed" << std::endl;
    }
}