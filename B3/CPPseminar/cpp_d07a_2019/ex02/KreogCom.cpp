/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : _m_serial(serial), _x(x), _y(y)
{
    _next = nullptr;
    _prev = nullptr;
    std::cout << "KreogCom " << _m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    KreogCom *prev = nullptr;
    KreogCom *next = nullptr;
    std::cout << "KreogCom " << _m_serial << " shutting down"
              << std::endl;
    prev = this->_prev;
    next = this->_next;
    if (prev) {
        prev->_next = next;
        next->_prev = prev;
    }
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);

    newCom->_next = this->_next;
    this->_next = newCom;
    newCom->_prev = this;
}

KreogCom* KreogCom::getCom()
{
    return (_next);
}

void KreogCom::removeCom()
{
    if (!_next) {
        return;
    }
    delete _next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << _m_serial << " currently at " << _x << " " <<
    _y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = _next;
    while (tmp) {
        tmp->ping();
        tmp = tmp->_next;
    }
    this->ping();
}

int main ()
{
    KreogCom k(42, 42, 101010);
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.addCom(73, 34, 510);

    k.locateSquad();
    k.removeCom();
    k.removeCom();
    return (0);
}