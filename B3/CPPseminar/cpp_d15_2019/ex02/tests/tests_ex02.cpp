/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"
#include "../ex02.hpp"

Test(Ex02, test00, .init=redirect_all_std)
{
    int tab [2] = {3 , 0};
    int minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl ;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl ;
    cr_assert_stdout_eq_str("template min\n"
                            "templateMin(tab, 2) = 0\n"
                            "non-template min\n"
                            "nonTemplateMin(tab, 2) = 0\n");
}

Test(Ex02, test01, .init=redirect_all_std)
{
    int tab[5] = {3, 3, 5, 2, 1};
    int minimum = templateMin(tab, 5);
    std::cout << "templateMin(tab, 5) = " << minimum << std::endl ;
    minimum = nonTemplateMin(tab, 5);
    std::cout << "nonTemplateMin(tab, 5) = " << minimum << std::endl ;
    cr_assert_stdout_eq_str("template min\n"
                            "template min\n"
                            "template min\n"
                            "template min\n"
                            "templateMin(tab, 5) = 1\n"
                            "non-template min\n"
                            "non-template min\n"
                            "non-template min\n"
                            "non-template min\n"
                            "nonTemplateMin(tab, 5) = 1\n");
}