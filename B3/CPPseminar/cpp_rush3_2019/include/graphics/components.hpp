/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

typedef struct elements_e {
    /* USER */
    sf::RenderWindow _window;
    sf::Font font;
    sf::Event event;

    sf::Text T_username;
    std::string username;
    
    sf::Text T_hostname;
    std::string hostname;

    sf::Text T_home;
    std::string home;

    sf::Text T_getuptime;
    std::string getuptime;

    /* DATE */
    sf::Text T_getTime;
    std::string getTime;

    sf::Text T_getDate;
    std::string getDate;

    /* RAM */
    sf::Text T_RamFree;
    std::string RamFree;

    sf::Text T_RamUsed;
    std::string RamUser;

    sf::Text T_swapFree;
    std::string swapFree;

    sf::Text T_SwapUsed;
    std::string SwapUsed;

    sf::Text T_pcRamFree;
    std::string pcRamFree;

    sf::Text T_pcRamUsed;
    std::string pcRamUsed;
    /* OS */
    sf::Text T_osName;
    std::string osName;
    
    sf::Text T_kernelVersion;
    std::string kernelVersion;
    /* CPU */
    sf::Text T_modelName;
    std::string modelName;

    sf::Text T_activTask;
    std::string activeTask;

    sf::Text T_coreNumber;
    std::string coreNumber;

}elements_t;

#endif