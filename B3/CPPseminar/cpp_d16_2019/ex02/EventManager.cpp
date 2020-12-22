/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#include "EventManager.hpp"

EventManager::EventManager() : _currentTime(0)
{
}

EventManager::EventManager(EventManager const &other) : _currentTime(other
._currentTime), _events(other._events)
{
}

EventManager& EventManager::operator=(EventManager const &rhs)
{
    _currentTime = rhs._currentTime;
    _events = rhs._events;
    return *this;
}

EventManager::~EventManager()
{
    _events.clear();
}

bool EventManager::cmp(const Event &e1, const Event &e2)
{
    if (e1.getTime() < e2.getTime())
        return true;
    return false;
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() >= _currentTime)
        _events.push_back(e);
    _events.sort(cmp);
}

void EventManager::addEventList(std::list <Event> &events)
{
    for (std::list<Event>::iterator it = events.begin(); it != events.end()
        ; it++) {
        addEvent(*it);
    }
}

void EventManager::addTime(unsigned int time)
{
    for (unsigned int i = _currentTime; i <= _currentTime + time; i++) {
        dumpEventDescAt(i);
    }
    for (unsigned int i = _currentTime; i <= _currentTime + time; i++) {
        removeEventsAt(i);
    }
    _currentTime += time;
}

void EventManager::dumpEventDescAt(unsigned int time) const
{
    for (std::list<Event>::const_iterator it = _events.begin(); it != _events
        .end()
        ; it++) {
        if (it->getTime() == time)
            std::cout << it->getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (std::list<Event>::const_iterator it = _events.begin(); it != _events
    .end()
        ; it++) {
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::dumpEvents() const
{
    for (std::list<Event>::const_iterator it = _events.begin(); it != _events
    .end()
        ; it++) {
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (std::list<Event>::iterator it = _events.begin(); it != _events.end()
    ; it++) {
        if (it->getTime() == time) {
            it = _events.erase(it);
            it--;
        }
    }
}