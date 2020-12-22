/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: display and inits elements
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../interfaces/IMonitorDisplay.hpp"
#include "components.hpp"
#include "../RAMModule.hpp"
#include "../OSModule.hpp"
#include "../UserModule.hpp"
#include "../CPUModule.hpp"

class sfmlGraph : public IMonitorDisplay {
    bool select;
    protected :
        elements_t *elem;
    public :
        sfmlGraph();
        ~sfmlGraph();
        elements_t *get_elem() const;
        void displayCPUModule(CPUModule const &module);
        void displayDateModule(DateModule const &module);
        void displayOSModule(OSModule const &module);
        void displayRAMModule(RAMModule const &module);
        void displayUserModule(UserModule const &module);
};

#endif
