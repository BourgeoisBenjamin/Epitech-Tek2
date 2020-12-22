/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(FruitBox, creation_test, .init=redirect_all_std)
{
    FruitBox box(12);
    cr_assert_eq(box.nbFruits(), 0);
    cr_assert_eq(box.head(), nullptr);
}

Test(FruitBox, delete_test, .init=redirect_all_std)
{
    FruitBox *box = new FruitBox(12);
    cr_assert_eq(box->nbFruits(), 0);
    delete box;
}

Test(FruitBox, advanced_test, .init=redirect_all_std)
{
    FruitBox fb(2);
    Banana *IMABANANA = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(new Lemon) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() != NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(new Banana) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    delete IMABANANA;
    cr_assert_stdout_eq_str("0\n"
                            "true\n"
                            "true\n"
                            "0\n"
                            "true\n"
                            "1\n"
                            "false\n"
                            "1\n"
                            "false\n"
                            "1\n"
                            "true\n"
                            "2\n"
                            "true\n"
                            "true\n"
                            "1\n"
                            "true\n"
                            "2\n"
                            "true\n"
                            "1\n"
                            "true\n"
                            "0\n"
                            "true\n"
                            "0\n");
}

Test(FruitBox, advanced_test_2, .init=redirect_all_std)
{
    FruitBox fb(0);
    FruitBox fb2(-1);
    Banana *IMABANANA = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb2.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    delete IMABANANA;
    cr_assert_stdout_eq_str("0\n"
                            "true\n"
                            "true\n"
                            "false\n"
                            "true\n"
                            "true\n"
                            "0\n"
                            "0\n"
                            "true\n"
                            "true\n"
                            "false\n"
                            "true\n"
                            "true\n"
                            "0\n");
}

Test(FruitBox, advanced_test_3, .init=redirect_all_std)
{
    FruitBox fb(4);
    Banana *IMABANANA = new Banana;
    Banana *IMABANANA2 = new Banana;
    Banana *IMABANANA3 = new Banana;
    Banana *IMABANANA4 = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA2) <<
    std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA3) <<
    std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA2) <<
    std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA4) <<
    std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    delete IMABANANA;
    delete IMABANANA2;
    delete IMABANANA3;
    delete IMABANANA4;
    cr_assert_stdout_eq_str("0\n"
                            "true\n"
                            "true\n"
                            "true\n"
                            "false\n"
                            "true\n"
                            "4\n");
}
