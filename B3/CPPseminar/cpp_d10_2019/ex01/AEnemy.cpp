/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _type(type), _hp(hp)
{

}

AEnemy::~AEnemy()
{
}

int AEnemy::getHP() const
{
    return _hp;
}

const std::string& AEnemy::getType() const
{
    return _type;
}

void AEnemy::takeDamage(int damage)
{
    if (damage <= 0)
        return;
    _hp -= damage;
}