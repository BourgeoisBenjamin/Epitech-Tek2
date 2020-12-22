/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D16_2019_EVENT_HPP
#define CPP_D16_2019_EVENT_HPP

#include <list>
#include <string>

class Event
{
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);

        unsigned int getTime() const;
        const std::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(const std::string &event);
    private:
        unsigned int _time;
        std::string _event;
};

#endif //CPP_D16_2019_EVENT_HPP
