/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D06_2019_SICKKOALALIST_HPP
#define CPP_D06_2019_SICKKOALALIST_HPP

#include "SickKoala.hpp"

class SickKoalaList
{
    private:
        SickKoala *_koala;
        SickKoalaList *_next;
    public:
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();

        bool isEnd();
        void append(SickKoalaList *next);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *remove);
        SickKoalaList *removeFromName(std::string remove);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
};

#endif //CPP_D06_2019_SICKKOALALIST_HPP
