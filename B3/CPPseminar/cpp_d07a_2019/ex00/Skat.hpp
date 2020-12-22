/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07A_2019_SKAT_HPP
#define CPP_D07A_2019_SKAT_HPP

#include <string>
#include <iostream>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        const std::string &name() const;

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        const std::string _name;
        int _stimPaks;
};

#endif //CPP_D07A_2019_SKAT_HPP
