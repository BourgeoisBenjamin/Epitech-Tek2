/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title) : _name
(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will "
                                            "never be the same!" << std::endl;
}

const std::string Sorcerer::getName() const
{
    return _name;
}

const std::string Sorcerer::getTitle() const
{
    return _title;
}

std::ostream& operator<<(std::ostream &os, const Sorcerer &sorcerer)
{
    return os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
    << ", and I like ponies!"  << std::endl;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}
