/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level),
Mage(name, level)
{
    _class = "Priest";
    _race = "Orc";
    _pv = 100;
    _power = 100;
    _strength = 4;
    _stamina = 4;
    _intelligence = 42;
    _spirit = 21;
    _agility = 2;
    Range = Character::CLOSE;
    std::cout << _name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 10;
    std::cout << _name << " uses a spirit explosion" << std::endl;
    this->Range = Character::RANGE;
    return (10 +_spirit);
}

void Priest::Heal()
{
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return;
    }
    _power -= 10;
    _pv += 70;
    if (_pv > 100)
        _pv = 100;
    std::cout << _name << " casts a little heal spell" << std::endl;
}