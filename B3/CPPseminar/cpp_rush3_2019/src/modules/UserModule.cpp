/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "../../include/UserModule.hpp"
#include <fstream>

UserModule::UserModule() : _name("User")
{
    this->setUsername();
    this->setHostname();
    this->setHome();
    this->setUptime();
}

UserModule::~UserModule()
{

}

UserModule::UserModule(const UserModule &copy) : _name(copy._name), _username
(copy._username), _hostname(copy._hostname), _home(copy._home), _uptime(copy
._uptime)
{
}

UserModule& UserModule::operator=(const UserModule &rhs)
{
    _username = rhs._username;
    _hostname = rhs._hostname;
    _home = rhs._home;
    _uptime = rhs._uptime;
    return *this;
}

const std::string & UserModule::getModuleName() const
{
    return _name;
}

bool UserModule::refreshInfoModule()
{
    this->setUsername();
    this->setHostname();
    this->setHome();
    this->setUptime();
    return true;
}

/* SPECIFIC */

void UserModule::setUsername()
{
    _username = std::string(std::getenv("USER"));
}

void UserModule::setHostname()
{
    _hostname = std::string(std::getenv("HOSTNAME"));
}

void UserModule::setHome()
{
    _home = std::string(std::getenv("HOME"));
}

std::string const & UserModule::getHome() const
{
    return _home;
}

std::string const & UserModule::getHostname() const
{
    return _hostname;
}

std::string const & UserModule::getUsername() const
{
    return _username;
}

void UserModule::setUptime()
{
    std::ifstream uptimeFile("/proc/uptime");
    std::string uptime;
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    if (!uptimeFile.is_open()) {
        _uptime = std::string("00 Hours 00 Minutes 00 Seconds");
        return;
    }
    std::getline(uptimeFile, uptime);
    uptime = uptime.substr(0, uptime.find(" "));
    seconds = std::stoi(uptime);
    minutes = seconds / 60;
    hours = minutes / 60;
    _uptime = std::string(std::to_string(hours) + " Hours " + std::to_string(
        (minutes % 60)) + " Minutes " + std::to_string((seconds % 60)) + " Seconds");
    uptimeFile.close();
}

std::string const & UserModule::getUptime() const
{
    return _uptime;
}

