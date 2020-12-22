/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "KoalaDoctorList.hpp"
#include <iostream>
#include <ostream>


KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor) : _doctor(doctor), _next
    (nullptr)
{
}

KoalaDoctorList::~KoalaDoctorList()
{
    this->_next = nullptr;
}

bool KoalaDoctorList::isEnd()
{
    if (_next)
        return (true);
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *next)
{
    if (!next)
        return;
    if (!_next)
        _next = next;
    else
        _next->append(next);
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    if (_doctor->getName() == name)
        return (_doctor);
    if (_next)
        return (_next->getFromName(name));
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *remove)
{
    if (!remove)
        return (nullptr);
    KoalaDoctorList *temp = nullptr;
    if (this == remove) {
        temp = this->_next;
        this->~KoalaDoctorList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next == remove) {
        temp = this->_next->_next;
        this->_next->~KoalaDoctorList();
        this->_next = temp;
        return (this);
    }
    this->_next->remove(remove);
    return (this);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string remove)
{
    KoalaDoctorList *temp = this;
    if (this->_doctor->getName() == remove) {
        temp = this->_next;
        this->~KoalaDoctorList();
        return (temp);
    }
    if (!this->_next)
        return (nullptr);
    if (this->_next->_doctor->getName() == remove) {
        temp = this->_next->_next;
        this->_next->~KoalaDoctorList();
        this->_next = temp;
        return (this);
    }
    this->_next->removeFromName(remove);
    return (this);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *temp = this;
    std::cout << "Doctors: ";

    while (temp) {
        if (!temp->_doctor)
            std::cout << "[nullptr]";
        else
            std::cout << temp->_doctor->getName();
        if (temp->_next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        temp = temp->_next;
    }
}