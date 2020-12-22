/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_IMONITORDISPLAY_HPP
#define CPP_RUSH3_2019_IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "../DateModule.hpp"
#include "../UserModule.hpp"
#include "../RAMModule.hpp"
#include "../OSModule.hpp"
#include "../CPUModule.hpp"

class IMonitorDisplay
{
    public:
        virtual ~IMonitorDisplay() {};
        virtual void displayCPUModule(CPUModule const &module) = 0;
        virtual void displayDateModule(DateModule const &module) = 0;
        virtual void displayOSModule(OSModule const &module) = 0;
        virtual void displayRAMModule(RAMModule const &module) = 0;
        virtual void displayUserModule(UserModule const &module) = 0;
        typedef enum Mode_e {
            NCURSES,
            SFML
        } Mode;
};

#endif //CPP_RUSH3_2019_IMONITORDISPLAY_HPP
