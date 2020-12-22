/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_DATEMODULE_HPP
#define CPP_RUSH3_2019_DATEMODULE_HPP

#include "interfaces/IMonitorModule.hpp"
#include "ctime"

class DateModule : public IMonitorModule
{
    public:
        DateModule();
        ~DateModule();
        DateModule(const DateModule &);
        DateModule&operator=(const DateModule& rhs);
        bool refreshInfoModule();
        const std::string &getModuleName() const;
        /* SPECIFIC */
        const std::time_t &getTimeStrut() const;
        std::tm* getLocalTimeStruct() const;
        std::string getTimeDate() const;
        std::string getDate() const;
        std::string getTime() const;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
    private:
        const std::string _name;
        std::time_t _now;
        std::tm *_localtime;
};

#endif //CPP_RUSH3_2019_DATEMODULE_HPP
