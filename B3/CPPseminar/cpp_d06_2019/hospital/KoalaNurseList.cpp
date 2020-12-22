/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "KoalaNurseList.hpp"
#include <iostream>
#include <ostream>

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse) : _nurse(nurse), _next
(nullptr)
{
}

KoalaNurseList::~KoalaNurseList()
{
    this->_next = nullptr;
}

bool KoalaNurseList::isEnd()
{
    if (_next)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *next)
{
    if (!next)
        return;
    if (!_next)
        _next = next;
    else
        _next->append(next);
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    if (_nurse->getID() == id)
        return (_nurse);
    if (_next)
        return (_next->getFromID(id));
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *remove)
{
    if (!remove)
        return (nullptr);
    KoalaNurseList *temp = nullptr;
    if (this == remove) {
        temp = this->_next;
        this->~KoalaNurseList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next == remove) {
        temp = this->_next->_next;
        this->_next->~KoalaNurseList();
        this->_next = temp;
        return (this);
    }
    this->_next->remove(remove);
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int remove)
{
    KoalaNurseList *temp = this;
    if (this->_nurse->getID() == remove) {
        temp = this->_next;
        this->~KoalaNurseList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next->_nurse->getID() == remove) {
        temp = this->_next->_next;
        this->_next->~KoalaNurseList();
        this->_next = temp;
        return (this);
    }
    this->_next->removeFromID(remove);
    return (this);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *temp = this;
    std::cout << "Nurses: ";

    while (temp) {
        if (!temp->_nurse)
            std::cout << "[nullptr]";
        else
            std::cout << temp->_nurse->getID();
        if (temp->_next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        temp = temp->_next;
    }
}