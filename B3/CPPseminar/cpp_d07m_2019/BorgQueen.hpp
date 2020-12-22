/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07M_2019_BORGQUEEN_HPP
#define CPP_D07M_2019_BORGQUEEN_HPP


namespace Borg {
    class BorgQueen;
}

#include "Borg.hpp"
#include "Federation.hpp"

namespace Borg {
    class BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();

            bool move(Borg::Ship *ship, Destination dest);
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
            void destroy(Borg::Ship *ship, Federation::Ship *target);

            bool (Borg::Ship::*movePtr)(Destination);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
            void (Borg::Ship::*destroyPtr)(Federation::Ship*);
        };
};

#endif //CPP_D07M_2019_BORGQUEEN_HPP
