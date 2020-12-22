/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D14M_2019_FRUIT_HPP
#define CPP_D14M_2019_FRUIT_HPP

#include <string>

class Fruit
{
    public:
        Fruit(std::string const &name, int vitamins);
        virtual ~Fruit();
        virtual int getVitamins() const;
        virtual std::string getName() const;
    protected:
        std::string _name;
        int _vitamins;
};

#endif //CPP_D14M_2019_FRUIT_HPP
