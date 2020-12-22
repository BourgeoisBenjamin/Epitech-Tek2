/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D14M_2019_FRUITBOX_HPP
#define CPP_D14M_2019_FRUITBOX_HPP

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        FruitBox(int);
        ~FruitBox();

        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;
    private:
        int _size;
        int _fruitNb;
        FruitNode *_head;

};

#endif //CPP_D14M_2019_FRUITBOX_HPP
