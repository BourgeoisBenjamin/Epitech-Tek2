/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_ITABLE_HPP
#define CPP_RUSH2_2019_ITABLE_HPP

#include <list>
#include <array>
#include "Toy.hpp"

class ITable
{
    public:
        virtual std::string* look() const = 0;
        void addToy(Toy*);
    protected:
        std::list<Toy*> _list;
};

#endif //CPP_RUSH2_2019_ITABLE_HPP
