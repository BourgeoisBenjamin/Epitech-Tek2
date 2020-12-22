/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D14M_2019_LITTLEHAND_HPP
#define CPP_D14M_2019_LITTLEHAND_HPP

#include "Fruit.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"
#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand
{
    public:
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
            FruitBox &bananas, FruitBox &limes);
        static FruitBox * const *organizeCoconut(Coconut const * const
        *coconuts);

};

#endif //CPP_D14M_2019_LITTLEHAND_HPP
