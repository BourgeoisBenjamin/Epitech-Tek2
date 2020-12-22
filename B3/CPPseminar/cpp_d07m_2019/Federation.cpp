/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#include "Federation.hpp"
#include <ostream>
#include <iostream>


Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
                                  short maxWarp, int torpedo) :
    _length(length), _width(width), _name (name), _maxWarp(maxWarp), _core
    (NULL), _captain(NULL), _home(EARTH), _location(EARTH), _shield(100),
    _photoTorpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished." <<
    std::endl << "It is " << _length << " m in length and " << _width << " m "
    "in width." << std::endl << "It can go to Warp " << _maxWarp << "!" <<
    std::endl;
    if (_photoTorpedo != 0)
        std::cout << "Weapons are set: " << _photoTorpedo << " torpedoes ready."
        << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stable;

    if (_core->checkReactor()->isStable())
        stable = "stable";
    else
        stable = "unstable";
    std::cout << "USS " << _name << ": The core is " << stable << " at the "
    "time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name) : _length
(length), _width(width), _name(name), _maxWarp(1), _core(NULL), _home(VULCAN),
_location(VULCAN)
{
    std::cout << "The independent ship " << _name << " just finished its "
    "construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m "
    "in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string stable;

    if (_core->checkReactor()->isStable())
        stable = "stable";
    else
        stable = "unstable";
    std::cout << _name << ": The core is " << stable << " at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0)
{
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << _captain->getName() << ": I'm glad to be the captain of the "
                                        "USS " << _name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= (int)_maxWarp && d != _location && _core->checkReactor()
    ->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= (int)_maxWarp && _core->checkReactor()
        ->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= (int)_maxWarp && d != _location && _core->checkReactor()
        ->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= (int)_maxWarp && _core->checkReactor()
        ->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move()
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield()
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (_photoTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photoTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    fire(1, target);
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes <= _photoTorpedo && _photoTorpedo != 0) {
        target->setShield(this->getShield() - (50 * torpedoes));
        _photoTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photoTorpedo << " torpedoes remaining." << std::endl;
        return;
    }
    if (torpedoes > _photoTorpedo) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (_core);
}