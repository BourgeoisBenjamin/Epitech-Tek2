/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D06_2019_KOALADOCTORLIST_HPP
#define CPP_D06_2019_KOALADOCTORLIST_HPP

#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
    private:
        KoalaDoctor *_doctor;
        KoalaDoctorList *_next;
    public:
        KoalaDoctorList(KoalaDoctor *doctor);
        ~KoalaDoctorList();

        bool isEnd();
        void append(KoalaDoctorList *next);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *remove);
        KoalaDoctorList *removeFromName(std::string remove);
        void dump();
};


#endif //CPP_D06_2019_KOALADOCTORLIST_HPP
