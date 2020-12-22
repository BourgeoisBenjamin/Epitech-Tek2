/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#include "../../include/OSModule.hpp"
#include "../../include/RAMModule.hpp"
#include "../../include/UserModule.hpp"
#include "../../include/CPUModule.hpp"
#include "../../include/DateModule.hpp"
#include "../../include/NetworkModule.hpp"
#include "../../include/ModuleElements.hpp"
#include "../../include/interfaces/IMonitorDisplay.hpp"
#include "../../include/interfaces/IMonitorModule.hpp"

ModuleElements::ModuleElements()
{}

ModuleElements::~ModuleElements()
{}

const UserModule &ModuleElements::getuserM() const
{
    return _userM;
}

const RAMModule &ModuleElements::getramM() const
{
    return _ramM;
}

const OSModule &ModuleElements::getosM() const
{
    return _osM;
}

const DateModule &ModuleElements::getdateM() const
{
    return _dateM;
}

const CPUModule &ModuleElements::getcpuM() const
{
    return _cpuM;
}

bool ModuleElements::refresh()
{
    if (!_userM.refreshInfoModule())
        return false;
    if (!_osM.refreshInfoModule())
        return false;
    if (!_dateM.refreshInfoModule())
        return false;
    if (!_ramM.refreshInfoModule())
        return false;
    if (!_cpuM.refreshInfoModule())
        return false;
    return true;
}