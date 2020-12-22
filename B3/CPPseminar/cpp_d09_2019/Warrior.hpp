/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_WARRIOR_HPP
#define CPP_D09_2019_WARRIOR_HPP

#include "Character.hpp"

class Warrior : virtual public Character
{
private:
    std::string _weaponName;
public:
    Warrior(const std::string &name, int level);
    ~Warrior();
    int CloseAttack();
    int RangeAttack();
};

#endif //CPP_D09_2019_WARRIOR_HPP
