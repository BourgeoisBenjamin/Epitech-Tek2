/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/Wrap.hpp"

Wrap::Wrap() : _object(nullptr), _open(true)
{
    _isTaken = false;
    _type = WRAP;
}

Wrap::~Wrap()
{
}

Object* Wrap::openMe()
{
    if (!_open) {
        _open = true;
        return _object;
    }
    return nullptr;
}

Object* Wrap::wrapMeThat(Object *object)
{
    if (!object) {
        std::cerr << "Nothing to wrap" << std::endl;
        return (nullptr);
    }
    if (!_open || _object) {
        std::cerr << "The wrap must be empty and open" << std::endl;
        return (nullptr);
    }
    _object = object;
    _open = false;
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return this;
}

bool Wrap::getOpen() const
{
    return _open;
}

void Wrap::setOpen(bool open)
{
    _open = open;
}

void Wrap::isTaken()
{
    if (!_isTaken) {
        _isTaken = true;
    }
}