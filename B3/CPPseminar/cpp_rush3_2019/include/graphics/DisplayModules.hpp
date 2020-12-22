/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#include "../interfaces/IMonitorDisplay.hpp"
#include "../ModuleElements.hpp"
#include "../graphics/SFML.hpp"
#include "../RAMModule.hpp"
#include "../CPUModule.hpp"

template<typename T>
int displayModules(T &display, ModuleElements elements)
{
        display.displayUserModule(elements.getuserM());
        display.displayRAMModule(elements.getramM());
        display.displayOSModule(elements.getosM());
        display.displayDateModule(elements.getdateM());
        display.displayCPUModule(elements.getcpuM());
        elements.refresh();
    return (0);
}