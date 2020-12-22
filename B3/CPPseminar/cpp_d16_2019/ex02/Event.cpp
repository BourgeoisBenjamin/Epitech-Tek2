/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#include "Event.hpp"

Event::Event() : _time(0)
{
}

Event::Event(unsigned int time, const std::string &event) : _time(time),
_event(event)
{
}

Event::~Event()
{
}

Event::Event(const Event &other) : _time(other._time), _event(other._event)
{
}

Event& Event::operator=(const Event &rhs)
{
    _time = rhs._time;
    _event = rhs._event;
    return *this;
}

const std::string & Event::getEvent() const
{
    return _event;
}

unsigned int Event::getTime() const
{
    return _time;
}

void Event::setEvent(const std::string &event)
{
    _event = event;
}

void Event::setTime(unsigned int time)
{
    _time = time;
}