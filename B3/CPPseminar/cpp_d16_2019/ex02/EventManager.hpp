/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D16_2019_EVENTMANAGER_HPP
#define CPP_D16_2019_EVENTMANAGER_HPP

#include "Event.hpp"
#include <list>
#include <string>
#include <ostream>
#include <iostream>

class EventManager
{
    public:
        EventManager();
        ~EventManager();
        EventManager(EventManager const &other);
        EventManager &operator=(EventManager const &rhs);

        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(std::list<Event> &events);
    private:
        unsigned int _currentTime;
        std::list<Event> _events;
        static bool cmp(const Event &e1, const Event &e2);
        void dumpEventDescAt(unsigned int time) const;
};

#endif //CPP_D16_2019_EVENTMANAGER_HPP
