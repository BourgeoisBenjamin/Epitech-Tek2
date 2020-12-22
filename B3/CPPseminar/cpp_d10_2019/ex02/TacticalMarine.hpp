/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_TACTICALMARINE_HPP
#define CPP_D10_2019_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include "ostream"
#include "iostream"

class TacticalMarine : public ISpaceMarine
{
    public:
        TacticalMarine();
        virtual ~TacticalMarine();

        virtual ISpaceMarine *clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
};
#endif //CPP_D10_2019_TACTICALMARINE_HPP
