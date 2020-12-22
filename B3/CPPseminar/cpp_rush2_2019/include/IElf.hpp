/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_IELF_HPP
#define CPP_RUSH2_2019_IELF_HPP

#include "Object.hpp"

class IElf
{
    public:
        virtual ~IElf(){};
    protected:
        Object *_hand;
};

#endif //CPP_RUSH2_2019_IELF_HPP
