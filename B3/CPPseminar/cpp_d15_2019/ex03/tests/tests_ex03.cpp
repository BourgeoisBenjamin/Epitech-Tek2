/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"
#include "../ex03.hpp"

Test(Ex03, test00, .init=redirect_all_std)
{
    int tab[] = {11, 3, 89, 42};
    foreach(tab, print<int>, 4);
    std::string tab2[] = {"j'", "aime", "les", "templates", "!"};
    foreach(tab2, print, 5);
    cr_assert_stdout_eq_str("11\n"
                            "3\n"
                            "89\n"
                            "42\n"
                            "j'\n"
                            "aime\n"
                            "les\n"
                            "templates\n"
                            "!\n");
}