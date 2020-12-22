/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D13_2019_TOYSTORY_HPP
#define CPP_D13_2019_TOYSTORY_HPP

#include <string>
#include "Toy.hpp"

class ToyStory
{
    public:
        typedef bool (Toy::*func)(const std::string &);
    public:
        static bool tellMeAStory(std::string const&, Toy&, func, Toy&, func);
};

#endif //CPP_D13_2019_TOYSTORY_HPP
