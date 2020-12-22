/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/SickKoala.hpp"

Test(delete_test, test00, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Benjamin");
    delete Koala;
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Benjamin: Kreooogg!! I'm cuuuured!\n");
}