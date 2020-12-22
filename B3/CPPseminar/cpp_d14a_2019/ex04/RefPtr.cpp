/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** TODO: add description
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr = nullptr) : _rawPtr(rawPtr)
{
}

RefPtr::~RefPtr()
{
    delete _rawPtr;
}

RefPtr& RefPtr::operator=(RefPtr const &other)
{
    _rawPtr = other.get();
    return *this;
}

RefPtr::RefPtr(RefPtr const &other) : _rawPtr(other._rawPtr)
{
}

BaseComponent* RefPtr::get() const
{
    return _rawPtr;
}