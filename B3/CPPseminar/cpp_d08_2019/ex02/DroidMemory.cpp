/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _fingerprint(random()), _exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getExp() const
{
    return (_exp);
}

size_t DroidMemory::getFingerprint() const
{
    return (_fingerprint);
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

DroidMemory& DroidMemory::operator<<(const DroidMemory &droidMemory)
{
    _exp += droidMemory.getExp();
    _fingerprint ^= droidMemory.getFingerprint();
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &droidMemory) const
{
    droidMemory.setExp(droidMemory.getExp() + _exp);
    droidMemory.setFingerprint(droidMemory.getFingerprint() ^ _fingerprint);
    return droidMemory;
}

DroidMemory& DroidMemory::operator+=(const DroidMemory &droidMemory)
{
    return *this << droidMemory;
}

DroidMemory& DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory& DroidMemory::operator+(const DroidMemory &droidMemory) const
{
    DroidMemory *newMemory = new DroidMemory();
    newMemory->setExp(_exp + droidMemory.getExp());
    newMemory->setFingerprint(_fingerprint ^ droidMemory
    .getFingerprint());
    return (*newMemory);
}

DroidMemory& DroidMemory::operator+(const size_t exp) const
{
    DroidMemory *newMemory = new DroidMemory();
    newMemory->setExp(_exp + exp);
    newMemory->setFingerprint(_fingerprint ^ exp);
    return (*newMemory);
}

std::ostream& operator<<(std::ostream &os, const DroidMemory &droidMemory)
{
    return os << "DroidMemory '" << droidMemory.getFingerprint() << "', " <<
    droidMemory.getExp();
}

/* EXO2 */

DroidMemory::DroidMemory(const DroidMemory &old) : _fingerprint(old.getFingerprint()),
_exp (old.getExp())
{
}

DroidMemory& DroidMemory::operator=(const DroidMemory &droidMemory)
{
    _exp = droidMemory.getExp();
    _fingerprint = droidMemory.getFingerprint();
    return *this;
}

bool DroidMemory::operator==(const DroidMemory &droidMemory) const
{
    return(_exp == droidMemory.getExp() && _fingerprint == droidMemory
    .getFingerprint
    ());
}

bool DroidMemory::operator!=(const DroidMemory &droidMemory) const
{
    return !(*this == droidMemory);
}

bool DroidMemory::operator<(const DroidMemory &droidMemory) const
{
    return _exp < droidMemory.getExp();
}

bool DroidMemory::operator<=(const DroidMemory &droidMemory) const
{
    return _exp <= droidMemory.getExp();
}

bool DroidMemory::operator>(const DroidMemory &droidMemory) const
{
    return _exp > droidMemory.getExp();
}

bool DroidMemory::operator>=(const DroidMemory &droidMemory) const
{
    return _exp >= droidMemory.getExp();
}

bool DroidMemory::operator<(const size_t exp) const
{
    return _exp < exp;
}

bool DroidMemory::operator<=(const size_t exp) const
{
    return _exp <= exp;
}

bool DroidMemory::operator>(const size_t exp) const
{
    return _exp > exp;
}

bool DroidMemory::operator>=(const size_t exp) const
{
    return _exp >= exp;
}