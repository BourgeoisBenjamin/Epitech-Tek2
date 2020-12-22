/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D14M_2019_FRUITNODE_HPP
#define CPP_D14M_2019_FRUITNODE_HPP

#include "Fruit.hpp"

typedef struct FruitNode_t
{
    Fruit *fruit;
    FruitNode_t *next;
} FruitNode;

#endif //CPP_D14M_2019_FRUITNODE_HPP
