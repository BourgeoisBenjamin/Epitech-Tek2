/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** test LittlePony
*/

#include "unittest.hpp"

Test(IsTaken, tests_LittlePony_00, .init = redirect_all_std)
{
    LittlePony *poney = new LittlePony("poney");
    poney->isTaken();
    cr_assert_stdout_eq_str("yo man\n");
    delete poney;
}