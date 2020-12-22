/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D06_2019_KOALADOCTOR_HPP
#define CPP_D06_2019_KOALADOCTOR_HPP

#include "KoalaNurse.hpp"

class KoalaDoctor
{
    private:
        std::string _name;
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        bool _work;
        void diagnose(SickKoala *SickKoala);
        void timeCheck();
        std::string getName();
};


#endif //CPP_D06_2019_KOALADOCTOR_HPP
