/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
                              FruitBox &bananas, FruitBox &limes)
{
    int nbFruit = unsorted.nbFruits();
    int fruitSorted = 0;
    Fruit *fruitToSort = nullptr;

    for (int i = 0; i < nbFruit; i++) {
        fruitToSort = unsorted.pickFruit();
        fruitSorted = bananas.nbFruits() + lemons.nbFruits() + limes.nbFruits();
        if (dynamic_cast<Banana*>(fruitToSort))
            bananas.putFruit(fruitToSort);
        else if (dynamic_cast<Lime*>(fruitToSort))
            limes.putFruit(fruitToSort);
        else if (dynamic_cast<Lemon*>(fruitToSort))
            lemons.putFruit(fruitToSort);
        if (fruitSorted == bananas.nbFruits() + lemons.nbFruits() + limes
        .nbFruits())
            unsorted.putFruit(fruitToSort);
    }
}