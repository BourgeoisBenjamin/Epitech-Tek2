/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_CHARACTER_HPP
#define CPP_D10_2019_CHARACTER_HPP

#include "ostream"
#include "iostream"
#include "string"
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const& getName() const;
        int getAp() const;
        AWeapon *getWeapon() const;
    private:
        const std::string _name;
        int _ap;
        AWeapon *_weapon;
};

std::ostream& operator<<(std::ostream &os, Character const &character);

#endif //CPP_D10_2019_CHARACTER_HPP
