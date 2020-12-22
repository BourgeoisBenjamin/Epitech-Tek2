/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "../../include/RAMModule.hpp"
#include <fstream>
#include <algorithm>
#include <iomanip>

RAMModule::RAMModule() : _name("RAM")
{
    this->setRam();
    this->setSwap();
}

RAMModule::RAMModule(const RAMModule &copy) : _name(copy._name)
{
    _ramUsed = copy._ramUsed;
    _ramFree = copy._ramFree;
    _ramTotal = copy._ramTotal;
    _pcRamUsed = copy._pcRamUsed;
    _pcRamFree = copy._pcRamFree;
    _swapUsed = copy._swapUsed;
    _swapFree = copy._swapFree;
    _swapTotal = copy._swapTotal;
    _pcSwapUsed = copy._pcSwapUsed;
    _pcSwapFree = copy._pcSwapFree;
}

RAMModule& RAMModule::operator=(const RAMModule &rhs)
{
    _ramUsed = rhs._ramUsed;
    _ramFree = rhs._ramFree;
    _ramTotal = rhs._ramTotal;
    _pcRamUsed = rhs._pcRamUsed;
    _pcRamFree = rhs._pcRamFree;
    _swapUsed = rhs._swapUsed;
    _swapFree = rhs._swapFree;
    _swapTotal = rhs._swapTotal;
    _pcSwapUsed = rhs._pcSwapUsed;
    _pcSwapFree = rhs._pcSwapFree;
    return *this;
}

RAMModule::~RAMModule()
{
}

const std::string & RAMModule::getModuleName() const
{
    return _name;
}

bool RAMModule::refreshInfoModule()
{
    this->setRam();
    this->setSwap();
    return true;
}

const std::string & RAMModule::getRamFree() const
{
    return _ramFree;
}

const std::string & RAMModule::getRamUsed() const
{
    return _ramUsed;
}

const std::string & RAMModule::getSwapFree() const
{
    return _swapFree;
}

const std::string & RAMModule::getSwapUsed() const
{
    return _swapUsed;
}

const std::string & RAMModule::getPcRamFree() const
{
    return _pcRamFree;
}

const std::string & RAMModule::getPcRamUsed() const
{
    return _pcRamUsed;
}

const std::string & RAMModule::getPcSwapFree() const
{
    return _pcSwapFree;
}

const std::string & RAMModule::getPcSwapUsed() const
{
    return _pcSwapUsed;
}

const std::string & RAMModule::getRamTotal() const
{
    return _ramTotal;
}

const std::string & RAMModule::getSwapTotal() const
{
    return _swapTotal;
}

void RAMModule::setRam()
{
    std::ifstream memInfoFile("/proc/meminfo");
    std::string memTotal, memFree;
    std::ostringstream out;
    if (!memInfoFile.is_open()) {
        _ramUsed = std::string("Ram Info Unavailable");
        _ramFree = std::string("Ram Info Unavailable");
        _pcRamUsed = std::string("Ram Info Unavailable");
        _pcRamFree = std::string("Ram Info Unavailable");
        return;
    }
    std::getline(memInfoFile, memTotal);
    std::getline(memInfoFile, memFree);

    std::remove_if(memTotal.begin(), memTotal.end(), isspace);
    std::remove_if(memFree.begin(), memFree.end(), isspace);

    memTotal = memTotal.substr(memTotal.find(":") + 1);
    memFree = memFree.substr(memFree.find(":") + 1);
    memFree = memFree.substr(0, memFree.find("k"));
    memTotal = memTotal.substr(0, memTotal.find("k"));

    this->setRamPercentage(memFree, memTotal);

    out << std::setprecision(2) << std::stod(memTotal) / (1024 *1024);
    _ramTotal = std::string(out.str() + "Gb");
    out.str("");
    out << std::setprecision(2) << ((std::stod(memTotal) - std::stod(memFree)) / (1024 * 1024));
    _ramUsed = std::string(out.str() + "Gb");
    out.str("");
    out << std::setprecision(2) << (std::stod(memFree) / (1024 * 1024));
    _ramFree = std::string(out.str() + "Gb");

    memInfoFile.close();
}

void RAMModule::setSwap()
{
    std::ifstream swapInfoFile("/proc/meminfo");
    std::string swapTotal, swapFree;
    std::ostringstream out;
    if (!swapInfoFile.is_open()) {
        _swapUsed = std::string("Swap Info Unavailable");
        _swapFree = std::string("Swap Info Unavailable");
        _pcSwapUsed = std::string("Swap Info Unavailable");
        _pcSwapFree = std::string("Swap Info Unavailable");
        return;
    }
    for (int i = 0; i < 14; i++)
        std::getline(swapInfoFile, swapTotal);
    std::getline(swapInfoFile, swapTotal);
    std::getline(swapInfoFile, swapFree);

    std::remove_if(swapTotal.begin(), swapTotal.end(), isspace);
    std::remove_if(swapFree.begin(), swapFree.end(), isspace);

    swapTotal = swapTotal.substr(swapTotal.find(":") + 1);
    swapFree = swapFree.substr(swapFree.find(":") + 1);
    swapFree = swapFree.substr(0, swapFree.find("k"));
    swapTotal = swapTotal.substr(0, swapTotal.find("k"));

    this->setSwapPercentage(swapFree, swapTotal);

    out << std::setprecision(2) << std::stod(swapTotal) / (1024 * 1024);
    _swapTotal = std::string(out.str() + "Gb");
    out.str("");
    out << std::setprecision(2) << ((std::stod(swapTotal) - std::stod(swapFree)) / (1024 * 1024));
    _swapUsed = std::string(out.str() + "Gb");
    out.str("");
    out << std::setprecision(2) << (std::stod(swapFree) / (1024 * 1024));
    _swapFree = std::string(out.str() + "Gb");

    swapInfoFile.close();
}

void RAMModule::setRamPercentage(const std::string &memFree, const
std::string &memTotal)
{
    double memFreeD = std::stod(memFree);
    double memTotalD = std::stod(memTotal);
    double memUsedD = memTotalD - memFreeD;
    std::ostringstream out;

    out << (memUsedD / memTotalD * 100);
    _pcRamUsed = std::string(out.str() + "%");
    out.str("");
    out << (memFreeD / memTotalD * 100);
    _pcRamFree = std::string(out.str() + "%");
}

void RAMModule::setSwapPercentage(const std::string &swapFree, const
std::string &swapTotal)
{
    double swapFreeD = std::stod(swapFree);
    double swapTotalD = std::stod(swapTotal);
    double swapUsedD = swapTotalD - swapFreeD;
    std::ostringstream out;

    out << (swapUsedD / swapTotalD * 100);
    _pcSwapUsed = std::string(out.str() + "%");
    out.str("");
    out << (swapFreeD / swapTotalD * 100);
    _pcSwapFree = std::string(out.str() + "%");
}