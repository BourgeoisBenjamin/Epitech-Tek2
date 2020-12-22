/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(LittleHand, advanced_test, .init=redirect_all_std)
{
    FruitBox	unsorted(9);
    unsorted.putFruit(new Lemon);
    unsorted.putFruit(new Banana);
    unsorted.putFruit(new Banana);
    unsorted.putFruit(new Lime);
    unsorted.putFruit(new Lemon);
    unsorted.putFruit(new Lime);
    unsorted.putFruit(new Lemon);
    unsorted.putFruit(new Banana);
    unsorted.putFruit(new Lime);

    FruitBox	lemons(2);
    FruitBox	bananas(2);
    FruitBox	limes(2);

    Fruit *f;

    LittleHand::sortFruitBox(unsorted, lemons, bananas, limes);

    std::cout << unsorted.nbFruits() << std::endl;
    std::cout << lemons.nbFruits() << std::endl;
    std::cout << bananas.nbFruits() << std::endl;
    std::cout << limes.nbFruits() << std::endl;

    f = lemons.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;
    f = lemons.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;

    f = bananas.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;
    f = bananas.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;

    f = limes.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;
    f = limes.pickFruit();
    std::cout << f->getName() << std::endl;
    delete f;

    FruitBox	f1(24);
    FruitBox	f2(11);
    FruitBox	f3(6);
    FruitBox	f4(6);

    int	i = -1;
    while (++i < 40)
    f1.putFruit(new Lemon);
    f1.pickFruit();
    f1.pickFruit();
    i = -1;
    while (++i < 40)
    f1.putFruit(new Lemon);
    i = -1;
    while (++i < 40)
    f1.pickFruit();
    i = -1;
    while (++i < 40)
    f1.putFruit(new Lemon);
    i = -1;
    while (++i < 40)
    f2.putFruit(new Lemon);
    i = -1;
    while (++i < 40)
    f3.putFruit(new Lemon);
    i = -1;
    while (++i < 40)
    f4.putFruit(new Lemon);

    std::cout << f1.nbFruits() << std::endl;
    std::cout << f2.nbFruits() << std::endl;
    std::cout << f3.nbFruits() << std::endl;
    std::cout << f4.nbFruits() << std::endl;
    cr_assert_stdout_eq_str("3\n"
                            "2\n"
                            "2\n"
                            "2\n"
                            "lemon\n"
                            "lemon\n"
                            "banana\n"
                            "banana\n"
                            "lime\n"
                            "lime\n"
                            "24\n"
                            "11\n"
                            "6\n"
                            "6\n");
}

Test(LittleHand, advanced_test_2, .init=redirect_all_std)
{
    {
    Coconut**		pack = new Coconut*[14];
    FruitBox * const *	boxes;
    int			i = -1;

    boxes = LittleHand::organizeCoconut(NULL);
    std::cout << boxes << std::endl;

    while (++i < 13)
        pack[i] = new Coconut;
    pack[i] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    i = -1;
    while (boxes[++i])
    {
    std::cout << boxes[i]->nbFruits() << std::endl;
    delete boxes[i];
    }
    delete [] boxes;

    pack = new Coconut*[1];
    pack[0] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    std::cout << boxes[0] << std::endl;
    delete [] boxes;
    }

    {
    Coconut**		pack = new Coconut*[19];
    FruitBox * const *	boxes;
    int			i = -1;

    boxes = LittleHand::organizeCoconut(NULL);
    std::cout << boxes << std::endl;

    while (++i < 18)
        pack[i] = new Coconut;
    pack[i] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    i = -1;
    while (boxes[++i])
    {
    std::cout << boxes[i]->nbFruits() << std::endl;
    delete boxes[i];
    }
    delete [] boxes;

    pack = new Coconut*[1];
    pack[0] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    std::cout << boxes[0] << std::endl;
    delete [] boxes;
    }
    cr_assert_stdout_eq_str("0\n"
                            "6\n"
                            "6\n"
                            "1\n"
                            "0\n"
                            "0\n"
                            "6\n"
                            "6\n"
                            "6\n"
                            "0\n");
}