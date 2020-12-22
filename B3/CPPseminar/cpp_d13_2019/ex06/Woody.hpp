/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D13_2019_WOODY_HPP
#define CPP_D13_2019_WOODY_HPP

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        Woody(std::string const &name, std::string const &filename = "woody.txt");
        ~Woody();
        bool speak(std::string const&);
};

#endif //CPP_D13_2019_WOODY_HPP
