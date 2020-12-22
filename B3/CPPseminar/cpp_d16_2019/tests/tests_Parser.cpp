/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Parser, test00, .init=redirect_all_std)
{
    Parser p;

    p.feed("((12*2)+14");
    std::cout << p.result() << std::endl;
    p.feed("((17%9) / 4)");
    std::cout << p.result() << std::endl;
    p.reset();
    p.feed("17 - 4 * 13");
    std::cout << p.result() << std::endl;
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");

    std::cout << p.result() << std::endl;
    cr_assert_stdout_eq_str("38\n40\n-35\n861\n");
}