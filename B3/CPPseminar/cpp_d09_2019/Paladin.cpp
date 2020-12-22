/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name,
    level), Warrior(name, level), Priest(name, level)
{
    _class = "Paladin";
    _race = "Human";
    _pv = 100;
    _power = 100;
    _strength = 9;
    _stamina = 10;
    _intelligence = 10;
    _spirit = 10;
    _agility = 2;
    Range = Character::CLOSE;
    std::cout << "the light falls on " << _name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::Intercept()
{
    return Warrior::RangeAttack();
}