/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_AWEAPON_HPP
#define CPP_D10_2019_AWEAPON_HPP

#include "ostream"
#include "iostream"
#include "string"

class AWeapon
{
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();
        std::string const &getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
    protected:
        const std::string _name;
        int _apcost;
        int _damage;
};

#endif //CPP_D10_2019_AWEAPON_HPP
