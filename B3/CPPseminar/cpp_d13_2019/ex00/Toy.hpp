/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D13_2019_TOY_HPP
#define CPP_D13_2019_TOY_HPP

#include "Picture.hpp"

class Toy
{
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
    public:
        Toy();
        Toy(enum ToyType type, const std::string name, const std::string
            filename);
        ~Toy();
        enum ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(const std::string&);
        bool setAscii(const std::string&);

    protected:
        enum ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif //CPP_D13_2019_TOY_HPP
