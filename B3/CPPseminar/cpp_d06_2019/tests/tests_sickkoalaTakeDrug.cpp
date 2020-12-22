/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/SickKoala.hpp"

Test(takeDrug, test00, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Benjamin");
    Koala->takeDrug("Mars");
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Benjamin: Mars, and it kreogs!\n");
}

Test(TakeDrug, test01, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Chloé");
    Koala->takeDrug("Buronzand");
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Chloé: And you'll sleep right away!\n");
}

Test(TakeDrug, test02, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Chloé");
    Koala->takeDrug("Chelou");
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Chloé: Goerkreog!\n");
}