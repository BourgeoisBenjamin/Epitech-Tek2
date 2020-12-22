/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_IMONITORMODULE_HPP
#define CPP_RUSH3_2019_IMONITORMODULE_HPP

#include "string"

class IMonitorModule
{
    public:
        virtual ~IMonitorModule() {};
        virtual bool refreshInfoModule() = 0;
        virtual const std::string& getModuleName() const = 0;
};

#endif //CPP_RUSH3_2019_IMONITORMODULE_HPP