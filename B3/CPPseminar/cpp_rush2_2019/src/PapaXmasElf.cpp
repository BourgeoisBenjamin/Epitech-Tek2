/*
** EPITECH PROJECT, 2019
** CPP RUSH2
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf()
{
    _hand = nullptr;
    std::cout << "[Elf] Hello, I'm a santa's elf ! Go to work!" << std::endl;
}

PapaXmasElf::~PapaXmasElf()
{
    std::cout << "[Elf] Work is finished ! Merry Chrismas !" << std::endl;
}