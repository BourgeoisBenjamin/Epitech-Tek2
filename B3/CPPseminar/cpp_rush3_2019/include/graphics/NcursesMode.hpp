/*
** EPITECH PROJECT, 2019
** CPP POOL RUSH 3
** File description:
** Header NcursesMode
*/

#ifndef NCURSESMODE_HPP_
#define NCURSESMODE_HPP_

#include "interfaces/IMonitorDisplay.hpp"
#include "./DateModule.hpp"
#include "./RAMModule.hpp"
#include "./UserModule.hpp"
#include "./OSModule.hpp"
#include "./CPUModule.hpp"
#include "./RAMModule.hpp"
#include <ncurses.h>

class NcursesMode : public IMonitorDisplay
{
    public:
        NcursesMode();
        ~NcursesMode();
        void displayCPUModule(CPUModule const &module);
        void displayDateModule(DateModule const &module);
        void displayOSModule(OSModule const &module);
        void displayRAMModule(RAMModule const &module);
        void displayUserModule(UserModule const &module);
        void setWindow();
    private:
        WINDOW* _date;
        WINDOW* _identity;
        WINDOW* _os;
        WINDOW* _cpu;
        WINDOW* _ram;
        void setDate(WINDOW *tmp);
        void setIdentity(WINDOW *tmp);
        void setOs(WINDOW *tmp);
        void setCPU(WINDOW *tmp);
        void setRam(WINDOW *tmp);
};

#endif // NCURSESMODE_HPP_