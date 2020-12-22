/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_POWERFIST_HPP
#define CPP_D10_2019_POWERFIST_HPP

#include "ostream"
#include "iostream"
#include "string"
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();
    void attack() const;
};

#endif //CPP_D10_2019_POWERFIST_HPP
