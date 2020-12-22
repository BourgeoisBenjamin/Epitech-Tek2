/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_SQUAD_HPP
#define CPP_D10_2019_SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

#include "iterator"
#include "list"

class Squad : public ISquad
{
    public:
        Squad();
        Squad(Squad const &squad);
        virtual ~Squad();

        int getCount() const;
        ISpaceMarine *getUnit(int position);
        int push(ISpaceMarine *marine);
        Squad& operator=(Squad const & squad);
    private:
        std::list<ISpaceMarine*> _list;
};

#endif //CPP_D10_2019_SQUAD_HPP
