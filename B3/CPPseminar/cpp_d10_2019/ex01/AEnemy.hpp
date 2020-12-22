/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_AENEMY_HPP
#define CPP_D10_2019_AENEMY_HPP

#include "ostream"
#include "iostream"
#include "string"

class AEnemy
{
public:
    AEnemy(int hp, const std::string &type);
    virtual ~AEnemy();

    virtual void takeDamage(int damage);
    std::string const &getType() const;
    int getHP() const;
protected:
    const std::string _type;
    int _hp;
};

#endif //CPP_D10_2019_AENEMY_HPP
