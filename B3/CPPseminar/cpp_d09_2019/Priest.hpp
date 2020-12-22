/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D09_2019_PRIEST_HPP
#define CPP_D09_2019_PRIEST_HPP

#include "Mage.hpp"

class Priest : public Mage
{
    private:
    public:
        Priest(const std::string&, int);
        ~Priest();

        int CloseAttack();
        void Heal();

};

#endif //CPP_D09_2019_PRIEST_HPP
