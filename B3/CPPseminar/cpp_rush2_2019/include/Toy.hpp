/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_TOY_HPP
#define CPP_RUSH2_2019_TOY_HPP

#include <string>
#include "Object.hpp"

class Toy : public Object {
    public :
        Toy(const std::string&);
        virtual ~Toy();
        void isTaken();
        const std::string getTitle() const;
    protected:
        const std::string _title;
};

#endif //CPP_RUSH2_2019_TOY_HPP
