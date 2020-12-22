/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "../../include/DateModule.hpp"

DateModule::DateModule() : _name("Date")
{
    _now = time(0);
    _localtime = localtime(&_now);
}

DateModule::~DateModule()
{
}

DateModule::DateModule(const DateModule &old) : _name(old._name), _now(old
._now), _localtime(old._localtime)
{
}

DateModule& DateModule::operator=(const DateModule &rhs)
{
    _now = rhs._now;
    _localtime = rhs._localtime;
    return *this;
}

bool DateModule::refreshInfoModule()
{
    _now = time(0);
    _localtime = localtime(&_now);
    return true;
}

const std::string &DateModule::getModuleName() const
{
    return _name;
}

const time_t & DateModule::getTimeStrut() const
{
    return _now;
}

std::tm * DateModule::getLocalTimeStruct() const
{
    return _localtime;
}

std::string DateModule::getTimeDate() const
{
    return std::ctime(&_now);
}

int DateModule::getYear() const
{
    return 1900 + _localtime->tm_year;
}

int DateModule::getMonth() const
{
    return _localtime->tm_mon;
}

int DateModule::getDay() const
{
    return _localtime->tm_mday;
}

int DateModule::getHour() const
{
    return _localtime->tm_hour;
}

int DateModule::getMinute() const
{
    return _localtime->tm_min;
}

int DateModule::getSecond() const
{
    return _localtime->tm_sec;
}

std::string DateModule::getDate() const
{
    std::string monthString[] = { "January", "February", "March", "April",
                                  "May", "June", "July", "August", "September", "October", "November", "December" };
    std::string dayString[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday" };

    return std::string(dayString[_localtime->tm_wday] + " " +
    std::to_string(_localtime->tm_mday) + " " + monthString[_localtime->tm_mon]
    + " " + std::to_string(_localtime->tm_year + 1900));

}

std::string DateModule::getTime() const
{
    return std::string(std::to_string(_localtime->tm_hour) + ":" +
    std::to_string(_localtime->tm_min) + ":" + std::to_string
    (_localtime->tm_sec));
}