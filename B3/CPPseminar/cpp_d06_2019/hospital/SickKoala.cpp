/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "SickKoala.hpp"
#include <ostream>
#include <iostream>

SickKoala::SickKoala(std::string name)
{
    _name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr."<< this->_name << ": Kreooogg!! I'm cuuuured!" <<
    std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr."<< this->_name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (!str.compare("Mars")) {
        std::cout << "Mr."<< this->_name << ": Mars, and it kreogs!" <<
        std::endl;
        return (true);
    }
    if (!str.compare("Buronzand")) {
        std::cout << "Mr."<< this->_name << ": And you'll sleep right away!" <<
        std::endl;
        return (true);
    }
    std::cout << "Mr."<< this->_name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    while (str.find("Kreog!") != std::string::npos)
        str.replace(str.find("Kreog!"), 6, "1337!");
    std::cout << "Mr."<< this->_name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return (_name);
}