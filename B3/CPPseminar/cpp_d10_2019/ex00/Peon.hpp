/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_PEON_HPP
#define CPP_D10_2019_PEON_HPP

#include "Victim.hpp"
#include <ostream>
#include <iostream>
#include <string>

class Peon : public Victim
{
    public:
        Peon(const std::string &name);
        ~Peon();
        void getPolymorphed() const final;
};

#endif //CPP_D10_2019_PEON_HPP
