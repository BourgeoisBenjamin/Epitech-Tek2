/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_TEDDY_HPP
#define CPP_RUSH2_2019_TEDDY_HPP

#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(const std::string&);
        ~Teddy();
        void isTaken() final;
};


#endif //CPP_RUSH2_2019_TEDDY_HPP
