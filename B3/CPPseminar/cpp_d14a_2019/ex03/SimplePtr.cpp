/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** TODO: add description
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{
}

SimplePtr::~SimplePtr()
{
    delete _rawPtr;
}

SimplePtr::SimplePtr(SimplePtr const &)
{
}

BaseComponent* SimplePtr::get() const
{
    return _rawPtr;
}

SimplePtr& SimplePtr::operator=(SimplePtr const &)
{
    return *this;
}
