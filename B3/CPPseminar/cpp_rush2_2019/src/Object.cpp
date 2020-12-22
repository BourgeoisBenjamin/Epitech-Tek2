/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Object.hpp"

Object::~Object()
{
}

bool Object::getIsTaken() const
{
    return _isTaken;
}

void Object::setIsTaken(bool isTaken)
{
    _isTaken = isTaken;
}

enum ObjectType Object::getType() const
{
    return _type;
}

Object *Object::wrapMeThat(Object *object)
{
    return object;
}

Object *Object::openMe()
{
    return nullptr;
}