/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_LITTLEPONY_HPP
#define CPP_RUSH2_2019_LITTLEPONY_HPP

#include "Toy.hpp"

class LittlePony : public Toy {
    public :
        LittlePony(const std::string&);
        ~LittlePony();
        void isTaken() final;
};

#endif //CPP_RUSH2_2019_LITTLEPONY_HPP
