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

FruitBox* const * LittleHand::organizeCoconut(const Coconut *const *coconuts)
{
    FruitBox **cocoSorted = nullptr;
    int nbPack = 0;
    int inWork = 0;
    int i = 0;
    Coconut *to_insert = nullptr;

    if (!coconuts) return (nullptr);

    for (nbPack = 0; coconuts[nbPack]; nbPack++);
    nbPack = nbPack / 6 + 2;
    cocoSorted = new FruitBox*[nbPack];

    while (coconuts[i]) {
        cocoSorted[inWork] = new FruitBox(6);
        for (int j = 0; j < 6 && coconuts[i + j]; j++) {
            to_insert = (const_cast<Coconut*>(coconuts[i + j]));
            cocoSorted[inWork]->putFruit(to_insert);
        }
        i += 6;
        inWork++;
    }
    cocoSorted[inWork] = nullptr;
    return cocoSorted;
}