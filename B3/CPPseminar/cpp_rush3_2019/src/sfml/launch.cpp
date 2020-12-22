/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../../include/graphics/SFML.hpp"
#include "../../include/graphics/DisplayModules.hpp"
#include <iostream>

sfmlGraph::sfmlGraph()
{
    select = false;
    elem = new elements_t();
}

sfmlGraph::~sfmlGraph()
{}

elements_t *sfmlGraph::get_elem() const
{
    return elem;
}

int launch_sfml()
{   
    ModuleElements elements;
    sfmlGraph sfml;
    elements_t *elem = sfml.get_elem();

    elem->coreNumber = std::to_string(elements.getcpuM().getCoreNumber());
    elem->activeTask = std::to_string(elements.getcpuM().getActiveTasks());
    elem->modelName = elements.getcpuM().getModelName();
    elem->username = elements.getuserM().getUsername();
    elem->hostname = elements.getuserM().getHostname();
    elem->home = elements.getuserM().getHome();
    elem->getuptime = elements.getuserM().getUptime();
    elem->getDate = elements.getdateM().getTime();
    elem->getTime = elements.getdateM().getDate();
    elem->RamFree = elements.getramM().getRamFree();
    elem->RamUser = elements.getramM().getRamUsed();
    elem->swapFree = elements.getramM().getSwapFree();
    elem->SwapUsed = elements.getramM().getSwapUsed();
    elem->pcRamFree = elements.getramM().getPcRamFree();
    elem->pcRamUsed = elements.getramM().getPcRamUsed();
    elem->osName = elements.getosM().getOSName();
    elem->kernelVersion = elements.getosM().getKernelVersion();

    elem->coreNumber += " -----> Core Number";
    elem->activeTask += " ------> Active Task";
    elem->modelName += " ------> Model Name";
    elem->username += " ------> User Name";
    elem->hostname += " ------> Host Name";
    elem->home += " ------> Home";
    elem->getuptime += " ------> Get up time";
    elem->getDate += " ------> Get date";
    elem->getTime += " ------> Get time";
    elem->RamFree += " ------> Ram free";
    elem->RamUser += " ------> Ram user";
    elem->swapFree += " ------> Swap free";
    elem->SwapUsed += " ------> Swap used";
    elem->pcRamFree += " ------> PC Ram free";
    elem->pcRamUsed += " ------> PC Ram used";
    elem->osName += " ------> osName";
    elem->kernelVersion += " ------> Kernel version";

    elem->font.loadFromFile("medias/police.otf");

    elem->T_activTask.setFont(elem->font);
    elem->T_coreNumber.setFont(elem->font);
    elem->T_modelName.setFont(elem->font);
    elem->T_username.setFont(elem->font);
    elem->T_hostname.setFont(elem->font);
    elem->T_home.setFont(elem->font);
    elem->T_getuptime.setFont(elem->font);
    elem->T_getTime.setFont(elem->font);
    elem->T_getDate.setFont(elem->font);
    elem->T_RamFree.setFont(elem->font);
    elem->T_RamUsed.setFont(elem->font);
    elem->T_swapFree.setFont(elem->font);
    elem->T_SwapUsed.setFont(elem->font);
    elem->T_pcRamFree.setFont(elem->font);
    elem->T_pcRamUsed.setFont(elem->font);
    elem->T_osName.setFont(elem->font);
    elem->T_kernelVersion.setFont(elem->font);

    elem->T_modelName.setString(elem->modelName);
    elem->T_activTask.setString(elem->activeTask);
    elem->T_coreNumber.setString(elem->coreNumber);
    elem->T_username.setString(elem->username);
    elem->T_hostname.setString(elem->hostname);
    elem->T_home.setString(elem->home);
    elem->T_getuptime.setString(elem->getuptime);
    elem->T_getTime.setString(elem->getTime);
    elem->T_getDate.setString(elem->getDate);
    elem->T_RamFree.setString(elem->RamFree);
    elem->T_RamUsed.setString(elem->RamUser);
    elem->T_swapFree.setString(elem->swapFree);
    elem->T_SwapUsed.setString(elem->SwapUsed);
    elem->T_pcRamFree.setString(elem->pcRamFree);
    elem->T_pcRamUsed.setString(elem->pcRamUsed);
    elem->T_osName.setString(elem->osName);
    elem->T_kernelVersion.setString(elem->kernelVersion);

    elem->T_modelName.setPosition(0, 520);
    elem->T_activTask.setPosition(0, 550);
    elem->T_coreNumber.setPosition(0, 580);
    elem->T_username.setPosition(0,0);
    elem->T_hostname.setPosition(0,30);
    elem->T_home.setPosition(0,60);
    elem->T_getuptime.setPosition(0,90);
    elem->T_getTime.setPosition(0,150);
    elem->T_getDate.setPosition(0,180);
    elem->T_RamFree.setPosition(0, 240);
    elem->T_RamUsed.setPosition(0, 270);
    elem->T_swapFree.setPosition(0, 300);
    elem->T_SwapUsed.setPosition(0, 330);
    elem->T_pcRamFree.setPosition(0,360);
    elem->T_pcRamUsed.setPosition(0, 390);
    elem->T_kernelVersion.setPosition(0, 450);
    elem->T_osName.setPosition(0, 480);

    elem->T_modelName.setCharacterSize(30);
    elem->T_activTask.setCharacterSize(30);
    elem->T_coreNumber.setCharacterSize(30);
    elem->T_username.setCharacterSize(30);
    elem->T_hostname.setCharacterSize(30);
    elem->T_home.setCharacterSize(30);
    elem->T_getuptime.setCharacterSize(30);
    elem->T_getTime.setCharacterSize(30);
    elem->T_getDate.setCharacterSize(30);
    elem->T_RamFree.setCharacterSize(30);
    elem->T_RamUsed.setCharacterSize(30);
    elem->T_swapFree.setCharacterSize(30);
    elem->T_SwapUsed.setCharacterSize(30);
    elem->T_pcRamFree.setCharacterSize(30);
    elem->T_pcRamUsed.setCharacterSize(30);
    elem->T_osName.setCharacterSize(30);
    elem->T_kernelVersion.setCharacterSize(30);

    elem->T_username.setFillColor(sf::Color::Red);
    elem->T_hostname.setFillColor(sf::Color::Red);
    elem->T_home.setFillColor(sf::Color::Red);
    elem->T_getuptime.setFillColor(sf::Color::Red);
    elem->T_getTime.setFillColor(sf::Color::Red);
    elem->T_getDate.setFillColor(sf::Color::Red);
    elem->T_RamFree.setFillColor(sf::Color::Red);
    elem->T_RamUsed.setFillColor(sf::Color::Red);
    elem->T_swapFree.setFillColor(sf::Color::Red);
    elem->T_SwapUsed.setFillColor(sf::Color::Red);
    elem->T_pcRamFree.setFillColor(sf::Color::Red);
    elem->T_pcRamUsed.setFillColor(sf::Color::Red);
    elem->T_kernelVersion.setFillColor(sf::Color::Red);
    elem->T_osName.setFillColor(sf::Color::Red);
    elem->T_modelName.setFillColor(sf::Color::Red);
    elem->T_activTask.setFillColor(sf::Color::Red);
    elem->T_coreNumber.setFillColor(sf::Color::Red);

    elem->_window.create(sf::VideoMode(1920, 1080), "Graphic");

     while (elem->_window.isOpen())
    {
        while (elem->_window.pollEvent(elem->event))
        {
            if (elem->event.type == sf::Event::Closed)
                elem->_window.close();
        }
        displayModules(sfml, elements);
        elem->_window.display();
    }
    return 0;
}