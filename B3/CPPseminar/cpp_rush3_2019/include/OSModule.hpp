/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_OSMODULE_HPP
#define CPP_RUSH3_2019_OSMODULE_HPP

#include "interfaces/IMonitorModule.hpp"

class OSModule : public IMonitorModule
{
    public:
        OSModule();
        ~OSModule();
        OSModule(const OSModule &);
        OSModule&operator=(const OSModule& rhs);
        const std::string &getModuleName() const;
        bool refreshInfoModule();

        void setKernelVersion();
        void setOSName();

        const std::string &getKernelVersion() const;
        const std::string &getOSName() const;

    private:
        const std::string _name;
        std::string _kernelVersion;
        std::string _osName;

};

#endif //CPP_RUSH3_2019_OSMODULE_HPP
