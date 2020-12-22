/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_SUPERMUTANT_HPP
#define CPP_D10_2019_SUPERMUTANT_HPP

#include "ostream"
#include "iostream"
#include "string"
#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
    public:
        SuperMutant();
        ~SuperMutant();
        void takeDamage(int damage);
};

#endif //CPP_D10_2019_SUPERMUTANT_HPP
