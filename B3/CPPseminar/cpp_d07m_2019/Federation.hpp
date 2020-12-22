/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D07M_2019_FEDERATION_HPP
#define CPP_D07M_2019_FEDERATION_HPP

namespace Federation {
    namespace Starfleet {
        class Ship;
        class Captain;
        class Ensign;
    }
    class Ship;
}

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        private:
            std::string _name;
            int _age;
        public:
            Captain(std::string);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int age);
        };
        class Ship
        {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _home;
                Destination _location;
                int _shield;
                int _photoTorpedo;

            public:
                Ship(int length = 289, int width = 132, std::string name =
                    "Entreprise", short maxWarp = 6, int torpedo = 0);
                ~Ship();

                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Federation::Starfleet::Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
        };
        class Ensign
        {
            private:
                std::string _name;
            public:
                Ensign(std::string);
                ~Ensign();
        };
    }
    class Ship
    {
        private:
            int _length;
            int _width;
            std::string _name;
            const short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
        public:
            Ship(int length, int width, std::string name);
            ~Ship();

            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core* getCore();
    };
}

#endif //CPP_D07M_2019_FEDERATION_HPP
