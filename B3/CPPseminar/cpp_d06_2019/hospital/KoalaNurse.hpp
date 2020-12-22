/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D06_2019_KOALANURSE_HPP
#define CPP_D06_2019_KOALANURSE_HPP

#include <string>
#include "SickKoala.hpp"

class KoalaNurse
{
    private:
        int _id;
    public:
        KoalaNurse(int id);
        ~KoalaNurse();

        bool _work;
        void giveDrug(std::string drug, SickKoala *SickKoala);
        std::string readReport(std::string report);
        void timeCheck();
        int getID();
};
#endif //CPP_D06_2019_KOALANURSE_HPP
