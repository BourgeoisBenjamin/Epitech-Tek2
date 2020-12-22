/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "SickKoalaList.hpp"
#include <iostream>
#include <ostream>

SickKoalaList::SickKoalaList(SickKoala *koala) : _koala(koala), _next(nullptr)
{
}

SickKoalaList::~SickKoalaList()
{
    this->_next = nullptr;
}

bool SickKoalaList::isEnd()
{
    if (_next)
        return (true);
    return (false);
}

void SickKoalaList::append(SickKoalaList *next)
{
    if (!next)
        return;
    if (!_next)
        _next = next;
    else
        _next->append(next);
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    if (_koala->getName() == name)
        return (_koala);
    if (_next)
        return (_next->getFromName(name));
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *remove)
{
    if (!remove)
        return nullptr;
    SickKoalaList *temp = nullptr;
    if (this == remove) {
        temp = this->_next;
        this->~SickKoalaList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next == remove) {
        temp = this->_next->_next;
        this->_next->~SickKoalaList();
        this->_next = temp;
        return (this);
    }
    this->_next->remove(remove);
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string remove)
{
    SickKoalaList *temp = this;
    if (this->_koala->getName() == remove) {
        temp = this->_next;
        this->~SickKoalaList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next->_koala->getName() == remove) {
        temp = this->_next->_next;
        this->_next->~SickKoalaList();
        this->_next = temp;
        return (this);
    }
    this->_next->removeFromName(remove);
    return (this);
}

SickKoala *SickKoalaList::getContent()
{
    return (_koala);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (_next);
}

void SickKoalaList::dump()
{
    SickKoalaList *temp = this;
    std::cout << "Patients: ";

    while (temp) {
        if (!temp->_koala)
            std::cout << "[nullptr]";
        else
            std::cout << temp->_koala->getName();
        if (temp->_next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        temp = temp->_next;
    }
}