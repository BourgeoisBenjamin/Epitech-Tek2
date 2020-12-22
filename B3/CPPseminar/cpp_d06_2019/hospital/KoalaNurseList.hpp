/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D06_2019_KOALANURSELIST_HPP
#define CPP_D06_2019_KOALANURSELIST_HPP

#include "KoalaNurse.hpp"

class KoalaNurseList
{
private:
    KoalaNurse *_nurse;
    KoalaNurseList *_next;
public:
    KoalaNurseList(KoalaNurse *nurse);
    ~KoalaNurseList();

    bool isEnd();
    void append(KoalaNurseList *next);
    KoalaNurse *getFromID(int id);
    KoalaNurseList *remove(KoalaNurseList *remove);
    KoalaNurseList *removeFromID(int remove);
    void dump();
};

#endif //CPP_D06_2019_KOALANURSELIST_HPP
