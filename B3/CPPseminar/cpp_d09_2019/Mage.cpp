/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character::Character(name,
    level)
{
    _class = "Mage";
    _race = "Gnome";
    _pv = 100;
    _power = 100;
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;
    Range = Character::CLOSE;
    std::cout << _name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 10;
    std::cout << _name << " blinks" << std::endl;
    this->Range = Character::RANGE;
    return (0);
}

int Mage::RangeAttack()
{
    if (_power < 25) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 25;
    std::cout << _name << " launches a fire ball" << std::endl;
    return (20 + _spirit);
}

void Mage::RestorePower()
{
    _power += 50 + _intelligence;
    if (_power > 100)
        _power = 100;
    std::cout << _name << " takes a mana potion" << std::endl;
}