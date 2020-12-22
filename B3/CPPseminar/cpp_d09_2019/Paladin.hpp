/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_PALADIN_HPP
#define CPP_D09_2019_PALADIN_HPP

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest
{
    public:
        Paladin(const std::string &, int);
        ~Paladin();
        using Priest::RangeAttack;
        using Priest::Heal;
        using Warrior::CloseAttack;
        using Character::RestorePower;
        int Intercept();
};

#endif //CPP_D09_2019_PALADIN_HPP
