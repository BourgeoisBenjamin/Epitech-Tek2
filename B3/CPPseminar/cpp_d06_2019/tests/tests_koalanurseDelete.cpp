/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/KoalaNurse.hpp"

Test(KoalaNursedelete_test, test00, .init = redirect_all_std)
{
    KoalaNurse *Nurse = new KoalaNurse(20);
    delete Nurse;
    fflush(stdout);
    cr_assert_stdout_eq_str("Nurse 20: Finally some rest!\n");
}