/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/KoalaNurse.hpp"

Test(KoalaNurseTimeCheck, test00, .init = redirect_all_std)
{
    KoalaNurse *Nurse = new KoalaNurse(39);
    Nurse->timeCheck();
    fflush(stdout);
    cr_assert_stdout_eq_str("Nurse 39: Time to get to work!\n");
}

Test(KoalaNurseTimeCheck, test01, .init = redirect_all_std)
{
    KoalaNurse *Nurse = new KoalaNurse(20);
    Nurse->timeCheck();
    Nurse->timeCheck();
    fflush(stdout);
    cr_assert_stdout_eq_str("Nurse 20: Time to get to work!\nNurse 20: Time "
                            "to go home to my eucalyptus forest!\n");
}