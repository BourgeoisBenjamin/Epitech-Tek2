/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_USERMODULE_HPP
#define CPP_RUSH3_2019_USERMODULE_HPP

#include "interfaces/IMonitorModule.hpp"

class UserModule : public IMonitorModule
{
    public:
        UserModule();
        ~UserModule();
        UserModule(const UserModule &);
        UserModule&operator=(const UserModule& rhs);
        const std::string &getModuleName() const;
        bool refreshInfoModule();

        std::string const &getUsername() const;
        std::string const &getHostname() const;
        std::string const &getHome() const;
        std::string const &getUptime() const;

    private:
        const std::string _name;
        std::string _username;
        std::string _hostname;
        std::string _home;
        std::string _uptime;

    private:
        void setUsername();
        void setHostname();
        void setHome();
        void setUptime();
};

#endif //CPP_RUSH3_2019_USERMODULE_HPP
