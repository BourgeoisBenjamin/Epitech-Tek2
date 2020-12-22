/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level),
Warrior(name, level), _weaponName("sword")
{
    _class = "Hunter";
    _race = "Elf";
    _pv = 100;
    _power = 100;
    _strength = 9;
    _stamina = 9;
    _intelligence = 6;
    _spirit = 6;
    _agility = 25;
    Range = Character::CLOSE;
    std::cout << _name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

int Hunter::RangeAttack()
{
    if (_power < 25) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 25;
    std::cout << _name << " uses his bow" << std::endl;
    return (20 + _agility);
}

void Hunter::RestorePower()
{
    _power += 100;
    if (_power > 100)
        _power = 100;
    std::cout << _name << " meditates" << std::endl;
}