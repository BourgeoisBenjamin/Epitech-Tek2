/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/SickKoala.hpp"

Test(overDrive, test00, .init = redirect_all_std)
{
    SickKoala *Koala = new SickKoala("Benjamin");
    Koala->overDrive("Wow! Kreog! Kreog?");
    fflush(stdout);
    cr_assert_stdout_eq_str("Mr.Benjamin: Wow! 1337! Kreog?\n");
}