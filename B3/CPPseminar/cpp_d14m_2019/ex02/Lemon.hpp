/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D14M_2019_LEMON_HPP
#define CPP_D14M_2019_LEMON_HPP

#include "Fruit.hpp"

class Lemon : public Fruit
{
    public:
        Lemon(std::string const &name = "lemon", int vitamins = 3);
        virtual ~Lemon();
    private:
};

#endif //CPP_D14M_2019_LEMON_HPP
