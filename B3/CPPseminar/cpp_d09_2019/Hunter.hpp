/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_HUNTER_HPP
#define CPP_D09_2019_HUNTER_HPP

#include "Warrior.hpp"

class Hunter : public Warrior
{
    private:
        std::string _weaponName;
    public:
        Hunter(const std::string &, int);
        ~Hunter();

        int RangeAttack();
        void RestorePower();
        using Warrior::CloseAttack;
        using Character::Heal;
};

#endif //CPP_D09_2019_HUNTER_HPP
