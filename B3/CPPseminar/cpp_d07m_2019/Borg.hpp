/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07M_2019_BORG_HPP
#define CPP_D07M_2019_BORG_HPP

namespace Borg {
    class Ship;
}

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Borg
{
    class Ship
    {
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
            int _shield;
            int _weaponFrequency;
            short _repair;
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();

            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();
    };
}

#endif //CPP_D07M_2019_BORG_HPP
