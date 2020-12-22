/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** test Teddy
*/

#include "unittest.hpp"

Test(IsTaken, test_Teddy_00, .init = redirect_all_std)
{
    Teddy *ourson = new Teddy("ourson");
    ourson->isTaken();
    cr_assert_stdout_eq_str("gra hu\n");
    delete ourson;
}