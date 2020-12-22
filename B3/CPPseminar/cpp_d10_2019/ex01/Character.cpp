/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _ap(40), _weapon
(nullptr)
{

}

Character::~Character()
{

}

const std::string &Character::getName() const
{
    return _name;
}

int Character::getAp() const
{
    return _ap;
}

AWeapon* Character::getWeapon() const
{
    return _weapon;
}

void Character::equip(AWeapon *weapon)
{
    if (!weapon)
        return;
    _weapon = weapon;
}

void Character::recoverAP()
{
    _ap += 10;
    if (_ap > 40)
        _ap = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (!_weapon || !enemy)
        return;
    if (_ap < _weapon->getAPCost())
        return;
    _ap -= _weapon->getAPCost();
    std::cout << _name << " attacks " << enemy->getType() << " with a " <<
    _weapon->getName() << std::endl;
    _weapon->attack();
    enemy->takeDamage(_weapon->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::ostream& operator<<(std::ostream &os, Character const &character)
{
    if (character.getWeapon())
        return os << character.getName() << " has " << character.getAp() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
    else
        return os << character.getName() << " has " << character.getAp() << ""
                                                                            " AP and is unarmed" << std::endl;
}