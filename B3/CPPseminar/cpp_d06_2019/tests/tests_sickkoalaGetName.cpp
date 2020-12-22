/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/SickKoala.hpp"

Test(getName, test00)
{
    SickKoala *Koala = new SickKoala("Benjamin");
    fflush(stdout);
    cr_assert_str_eq(Koala->getName().c_str(), "Benjamin");
    delete Koala;
}