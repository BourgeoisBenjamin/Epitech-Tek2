/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_CHARACTER_HPP
#define CPP_D09_2019_CHARACTER_HPP

#include <string>
#include <ostream>
#include <iostream>

class Character
{
protected:
    const std::string _name;
    std::string _class;
    std::string _race;
    int _level;
    int _pv;
    int _power;
    int _strength;
    int _stamina;
    int _intelligence;
    int _spirit;
    int _agility;
public:
    Character(const std::string &name, int level);
    ~Character();

    enum AttackRange
    {
        CLOSE,
        RANGE
    };
    enum AttackRange Range;
    const std::string &getName() const;
    int getLvl() const;
    int getPv() const;
    int getPower() const;
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
    void TakeDamage(int damage);
};

#endif //CPP_D09_2019_CHARACTER_HPP
