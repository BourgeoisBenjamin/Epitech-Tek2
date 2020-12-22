/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_BOX_HPP
#define CPP_RUSH2_2019_BOX_HPP

#include "Wrap.hpp"

class Box : public Wrap
{
    public :
        Box();
        ~Box();
        void closeMe();
    protected:
        Object *_object;
};

#endif //CPP_RUSH2_2019_BOX_HPP
