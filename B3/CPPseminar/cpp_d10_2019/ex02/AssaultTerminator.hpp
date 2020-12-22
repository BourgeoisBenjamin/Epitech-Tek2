/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_ASSAULTTERMINATOR_HPP
#define CPP_D10_2019_ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include "ostream"
#include "iostream"

class AssaultTerminator : public ISpaceMarine
{
    public:
        AssaultTerminator();
        virtual ~AssaultTerminator();

        virtual ISpaceMarine *clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
};

#endif //CPP_D10_2019_ASSAULTTERMINATOR_HPP
