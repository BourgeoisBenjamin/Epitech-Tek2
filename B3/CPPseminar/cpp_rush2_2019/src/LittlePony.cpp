/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/
#include "../include/LittlePony.hpp"

LittlePony::LittlePony(const std::string &title): Toy::Toy(title)
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    if (!_isTaken) {
        _isTaken = true;
        std::cout << "yo man" << std::endl;
    }
}