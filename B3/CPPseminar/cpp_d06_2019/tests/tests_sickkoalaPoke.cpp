/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/SickKoala.hpp"

Test(poke, test00, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Benjamin");
    Koala->poke();
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Benjamin: Gooeeeeerrk!!\n");
}

Test(poke, test01, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Chloé");
    Koala->poke();
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Chloé: Gooeeeeerrk!!\n");
}