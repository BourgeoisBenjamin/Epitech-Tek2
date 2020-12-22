/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D07M_2019_ADMIRAL_HPP
#define CPP_D07M_2019_ADMIRAL_HPP

#include <string>
#include <iostream>

namespace Federation {
    namespace Starfleet {
        class Admiral;
    };
};

#include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        class Admiral {
        public:
            Admiral(std::string);
            ~Admiral();
            bool (Federation::Starfleet::Ship::*movePtr)(Destination);
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship*);

            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);
        private:
            std::string _name;
        };
    };
};

#endif //CPP_D07M_2019_ADMIRAL_HPP
