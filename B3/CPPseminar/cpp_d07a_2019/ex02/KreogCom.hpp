/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07A_2019_KREOGCOM_HPP
#define CPP_D07A_2019_KREOGCOM_HPP

#include <iostream>
#include <ostream>

class KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping() const;
        void locateSquad() const;

    private:
        const int _m_serial;
        const int _x;
        const int _y;
        KreogCom *_prev;
        KreogCom *_next;
};

#endif //CPP_D07A_2019_KREOGCOM_HPP
