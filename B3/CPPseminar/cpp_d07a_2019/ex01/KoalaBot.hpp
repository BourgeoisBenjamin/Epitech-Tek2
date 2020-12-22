/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D07A_2019_KOALABOT_HPP
#define CPP_D07A_2019_KOALABOT_HPP

#include "Parts.hpp"

class KoalaBot
{
    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();

        void setParts(const Arms&);
        void setParts(const Legs&);
        void setParts(const Head&);
        void swapParts(Arms&);
        void swapParts(Legs&);
        void swapParts(Head&);
        void informations() const;
        bool status() const;
};
#endif //CPP_D07A_2019_KOALABOT_HPP
