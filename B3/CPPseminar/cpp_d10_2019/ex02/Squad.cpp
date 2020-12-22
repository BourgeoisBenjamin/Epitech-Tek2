/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "Squad.hpp"

Squad::Squad()
{
}

Squad::Squad(Squad const &squad) : _list(squad._list)
{
}

Squad::~Squad()
{
    std::list<ISpaceMarine*>::iterator it = _list.begin();
    while (it != _list.end()) {
        delete *it;
        it = _list.erase(it);
    }
}

int Squad::getCount() const
{
    return _list.size();
}

ISpaceMarine* Squad::getUnit(int position)
{
    auto it1 = std::next(_list.begin(), position);
    return (*it1);
}

Squad& Squad::operator=(Squad const &squad)
{
    std::list<ISpaceMarine*>::iterator it = _list.begin();
    while (it != _list.end()) {
        it = _list.erase(it);
    }
    _list = squad._list;
    return *this;
}

int Squad::push(ISpaceMarine *marine)
{
    if (!marine)
        return (getCount());
    std::list<ISpaceMarine*>::iterator it = _list.begin();
    while (it != _list.end()) {
        if (marine == *it)
            return getCount();
        it++;
    }
    _list.push_back(marine);
    return getCount();
}