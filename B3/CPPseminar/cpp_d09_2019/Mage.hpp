/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_MAGE_HPP
#define CPP_D09_2019_MAGE_HPP

#include "Character.hpp"

class Mage : virtual public Character
{
    public:
        Mage(const std::string &name, int level);
        ~Mage();
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
};

#endif //CPP_D09_2019_MAGE_HPP
