/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_RAMMODULE_HPP
#define CPP_RUSH3_2019_RAMMODULE_HPP

#include <string>
#include "interfaces/IMonitorModule.hpp"

class RAMModule : public IMonitorModule
{
    public:
        RAMModule();
        ~RAMModule();
        RAMModule(const RAMModule &);
        RAMModule&operator=(const RAMModule& rhs);
        const std::string &getModuleName() const;
        bool refreshInfoModule();

        const std::string& getRamUsed() const;
        const std::string& getRamFree() const;
        const std::string& getRamTotal() const;
        const std::string& getPcRamUsed() const;
        const std::string& getPcRamFree() const;
        const std::string& getSwapUsed() const;
        const std::string& getSwapFree() const;
        const std::string& getSwapTotal() const;
        const std::string& getPcSwapUsed() const;
        const std::string& getPcSwapFree() const;

    private:
        const std::string _name;
        std::string _ramUsed;
        std::string _ramFree;
        std::string _ramTotal;
        std::string _pcRamUsed;
        std::string _pcRamFree;
        std::string _swapUsed;
        std::string _swapFree;
        std::string _swapTotal;
        std::string _pcSwapUsed;
        std::string _pcSwapFree;

    private:
        void setRam();;
        void setSwap();
        void setRamPercentage(const std::string &, const std::string &);
        void setSwapPercentage(const std::string &, const std::string &);
};

#endif //CPP_RUSH3_2019_RAMMODULE_HPP
