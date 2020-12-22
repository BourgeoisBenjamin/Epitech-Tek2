/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07A_2019_PARTS_HPP
#define CPP_D07A_2019_PARTS_HPP

#include <string>
#include <ostream>
#include <iostream>

class Arms {
    private:
        std::string _serial;
        bool _functionnal;

    public:
        Arms(std::string serial = "A-01", bool functionnal = true);
        ~Arms();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
};

class Legs {
    private:
        std::string _serial;
        bool _functionnal;

    public:
        Legs(std::string serial = "L-01", bool functionnal = true);
        ~Legs();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
};

class Head {
    private:
        std::string _serial;
        bool _functionnal;

    public:
        Head(std::string serial = "H-01", bool functionnal = true);
        ~Head();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
};

#endif //CPP_D07A_2019_PARTS_HPP
