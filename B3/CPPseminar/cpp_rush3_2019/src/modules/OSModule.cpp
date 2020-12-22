/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "../../include/OSModule.hpp"
#include <fstream>

OSModule::OSModule() : _name("OS")
{
    this->setKernelVersion();
    this->setOSName();
}

OSModule::~OSModule()
{
}

OSModule::OSModule(const OSModule &copy) : _name(copy._name), _kernelVersion
(copy._kernelVersion), _osName(copy._osName)
{
}

OSModule& OSModule::operator=(const OSModule &rhs)
{
    _kernelVersion = rhs._kernelVersion;
    _osName = rhs._osName;
    return *this;
}

const std::string & OSModule::getModuleName() const
{
    return _name;
}

bool OSModule::refreshInfoModule()
{
    this->setKernelVersion();
    this->setOSName();
    return true;
}

void OSModule::setKernelVersion()
{
    std::ifstream kernelVersionFile("/proc/sys/kernel/osrelease");

    if (!kernelVersionFile.is_open()) {
        _kernelVersion = std::string("Version Unavailable");
        return;
    }
    std::getline(kernelVersionFile, _kernelVersion);
    kernelVersionFile.close();
}

void OSModule::setOSName()
{
    std::ifstream OSNameFile("/proc/sys/kernel/ostype");

    if (!OSNameFile.is_open()) {
        _osName = std::string("OS Name Unavailable");
        return;
    }
    std::getline(OSNameFile, _osName);
    OSNameFile.close();
}

const std::string & OSModule::getKernelVersion() const
{
    return _kernelVersion;
}

const std::string & OSModule::getOSName() const
{
    return _osName;
}