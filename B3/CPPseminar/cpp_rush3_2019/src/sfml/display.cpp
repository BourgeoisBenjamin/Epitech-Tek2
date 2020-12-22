/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#include "../../include/graphics/SFML.hpp"
#include "../../include/graphics/DisplayModules.hpp"
#include "../../include/UserModule.hpp"
#include "../../include/DateModule.hpp"
#include "../../include/CPUModule.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void sfmlGraph::displayCPUModule(CPUModule const &module)
{
    (void)module;
    elem->_window.draw(elem->T_modelName);
    elem->_window.draw(elem->T_coreNumber);
    elem->_window.draw(elem->T_activTask);
}

void sfmlGraph::displayOSModule(OSModule const &module)
{
    (void)module;
    elem->_window.draw(elem->T_kernelVersion);
    elem->_window.draw(elem->T_osName);
}

void sfmlGraph::displayDateModule(DateModule const &module)
{
    (void)module;
    elem->_window.draw(elem->T_getTime);
    elem->_window.draw(elem->T_getDate);
}
void sfmlGraph::displayRAMModule(RAMModule const &module)
{
    (void)module;
    elem->_window.draw(elem->T_RamFree);
    elem->_window.draw(elem->T_RamUsed);
    elem->_window.draw(elem->T_swapFree);
    elem->_window.draw(elem->T_SwapUsed);
    elem->_window.draw(elem->T_pcRamFree);
    elem->_window.draw(elem->T_pcRamUsed);
}
 void sfmlGraph::displayUserModule(UserModule const &module)
{
    (void)module;
    elem->_window.draw(elem->T_username);
    elem->_window.draw(elem->T_hostname);
    elem->_window.draw(elem->T_home);
    elem->_window.draw(elem->T_getuptime);
}