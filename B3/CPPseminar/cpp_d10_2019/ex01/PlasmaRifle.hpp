/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_PLASMARIFLE_HPP
#define CPP_D10_2019_PLASMARIFLE_HPP

#include "ostream"
#include "iostream"
#include "string"
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();
    void attack() const;
};

#endif //CPP_D10_2019_PLASMARIFLE_HPP
