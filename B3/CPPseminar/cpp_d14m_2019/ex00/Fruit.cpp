/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string const &name, int vitamins) : _name(name), _vitamins
(vitamins)
{
}

Fruit::~Fruit()
{
}

const std::string & Fruit::getName() const
{
    return _name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}