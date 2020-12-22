/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/KoalaNurse.hpp"

Test(getID, test00)
{
    KoalaNurse *Nurse = new KoalaNurse(30);
    fflush(stdout);
    cr_assert_eq(Nurse->getID(), 30);
    delete Nurse;
}