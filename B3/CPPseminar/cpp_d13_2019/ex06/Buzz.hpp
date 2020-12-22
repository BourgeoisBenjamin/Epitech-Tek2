/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D13_2019_BUZZ_HPP
#define CPP_D13_2019_BUZZ_HPP

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        Buzz(std::string const &name, std::string const &filename = "buzz.txt");
        ~Buzz();
        bool speak(std::string const&);
        bool speak_es(std::string const &);
};

#endif //CPP_D13_2019_BUZZ_HPP
