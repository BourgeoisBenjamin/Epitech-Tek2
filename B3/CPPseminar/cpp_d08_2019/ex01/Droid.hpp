/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D08_2019_DROID_HPP
#define CPP_D08_2019_DROID_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstddef>
#include "DroidMemory.hpp"

class Droid
{
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
        DroidMemory *_BattleData;
    public:
        Droid(std::string);
        ~Droid();

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        DroidMemory *getBattleData() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setBattleData(DroidMemory *droidMemory);

        Droid(const Droid &);
        Droid& operator=(const Droid &);
        bool operator==(const Droid &) const;
        bool operator!=(const Droid &) const;
        Droid& operator<<(size_t &);
};

std::ostream & operator<<(std::ostream & os, const Droid &);

#endif //CPP_D08_2019_DROID_HPP
