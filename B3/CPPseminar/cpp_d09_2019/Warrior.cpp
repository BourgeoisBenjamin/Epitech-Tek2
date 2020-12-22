/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) :
Character::Character(name, level), _weaponName("hammer")
{
    _class = "Warrior";
    _race = "Dwarf";
    _pv = 100;
    _power = 100;
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _spirit = 5;
    _agility = 7;
    Range = Character::CLOSE;
    std::cout << "I'm " << _name <<
              " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" <<
              std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (_power < 30) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 30;
    std::cout << _name << " strikes with his " << _weaponName << std::endl;
    return (20 + _strength);
}

int Warrior::RangeAttack()
{
    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 10;
    this->Range = CLOSE;
    std::cout << _name << " intercepts" << std::endl;
    return (0);
}