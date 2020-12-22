/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness(15)
{
    _status = new std::string("Standing by");
    _BattleData = new DroidMemory();
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
}

void Droid::setStatus(std::string *status)
{
    _status = status;
}

Droid::Droid(const Droid &droid) : _id(droid._id), _energy(50), _attack(25),
_toughness(15)
{
    _status = droid._status;
    _id = droid._id;
    _BattleData = droid._BattleData;
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid& Droid::operator=(const Droid &droid)
{
    _status = droid._status;
    _id = droid._id;
    _BattleData = droid._BattleData;
    return *this;
}

bool Droid::operator==(const Droid &droid) const
{
    if (*_status == *droid.getStatus())
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

DroidMemory* Droid::getBattleData() const
{
    return _BattleData;
}

void Droid::setBattleData(DroidMemory *droidMemory)
{
    _BattleData = droidMemory;
}

bool Droid::operator()(const std::string *task, size_t exp)
{
    if (this->getEnergy() <= 10) {
        this->setStatus(new std::string("Battery Low"));
        this->setEnergy(0);
        return (false);
    }
    this->setEnergy(this->getEnergy() - 10);
    if (this->getBattleData()->getExp() >= exp) {
        this->setStatus(new std::string(*task + " - Completed!"));
        this->getBattleData()->setExp(this->getBattleData()->getExp() + (exp / 2));
        return (true);
    }
    this->setStatus(new std::string(*task + " - Failed!"));
    this->getBattleData()->setExp(this->getBattleData()->getExp() + exp);
    return (false);
}