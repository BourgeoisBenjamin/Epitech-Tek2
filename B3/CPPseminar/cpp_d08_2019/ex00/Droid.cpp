/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness
(15)
{
    _status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (_id);
}

size_t Droid::getEnergy() const
{
    return (_energy);
}

size_t Droid::getAttack() const
{
    return (_attack);
}

size_t Droid::getToughness() const
{
    return (_toughness);
}

std::string *Droid::getStatus() const
{
    return (_status);
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = energy;
    if (_energy > 100)
        _energy = 100;
}

void Droid::setStatus(std::string *status)
{
    _status = status;
}

Droid::Droid(const Droid &droid) : _id(droid._id), _energy(droid._energy),
_attack(25), _toughness(15)
{
    if (droid._status)
        _status = new std::string(*droid.getStatus());
    else
        _status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid& Droid::operator=(const Droid &droid)
{
    _id = droid.getId();
    _energy = droid.getEnergy();
    if (_status)
        delete _status;
    _status = new std::string(*(droid.getStatus()));
    return *this;
}

bool Droid::operator==(const Droid &droid) const
{
    if (_id == droid.getId() && _energy == droid.getEnergy() && _attack ==
    droid.getAttack() && _toughness == droid.getToughness() && *_status ==
    *droid.getStatus())
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &droid) const
{
    return !(*this == droid);
}

Droid& Droid::operator<<(size_t &energy)
{
    size_t substract = 100 - _energy;
    if (energy < substract)
        substract = energy;
    if (_energy < 100) {
        _energy += substract;
        energy -= substract;
    }
    return(*this);
}

std::ostream& operator<<(std::ostream &os, const Droid &droid)
{
    return (os << "Droid '" << droid.getId() << "', " << *droid.getStatus() <<
    ", " << droid.getEnergy());
}