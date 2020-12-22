/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D10_2019_VICTIM_HPP
#define CPP_D10_2019_VICTIM_HPP

#include <ostream>
#include <iostream>
#include <string>

class Victim
{
    protected:
        const std::string _name;
    public:
        Victim(const std::string &name);
        ~Victim();

        const std::string getName() const;
        virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &os, const Victim &victim);

#endif //CPP_D10_2019_VICTIM_HPP
