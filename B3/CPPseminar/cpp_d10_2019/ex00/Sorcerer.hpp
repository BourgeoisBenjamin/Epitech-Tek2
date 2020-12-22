/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_SORCERER_HPP
#define CPP_D10_2019_SORCERER_HPP

#include "Victim.hpp"
#include <ostream>
#include <iostream>
#include <string>

class Sorcerer
{
    private:
        const std::string _name;
        const std::string _title;
    public:
        Sorcerer(const std::string &name, const std::string &title);
        ~Sorcerer();
        const std::string getName() const;
        const std::string getTitle() const;
        void polymorph(const Victim &victim) const;
};

std::ostream& operator<<(std::ostream &os, const Sorcerer &sorcerer);

#endif //CPP_D10_2019_SORCERER_HPP
