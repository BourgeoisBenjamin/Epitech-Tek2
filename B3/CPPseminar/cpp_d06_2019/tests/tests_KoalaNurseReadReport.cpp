/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"
#include "../hospital/KoalaNurse.hpp"

Test(KoalaNurseReadReport, test00, .init = redirect_all_std)
{
    KoalaNurse *Nurse = new KoalaNurse(14);
    Nurse->readReport("Test.report");
    fflush(stdout);
    cr_assert_stdout_eq_str("Nurse 14: Kreog! Mr.Test needs a Mars!\n");
}

Test(KoalaNurseReadReport, test01)
{
    KoalaNurse *Nurse = new KoalaNurse(14);
    fflush(stdout);
    cr_assert_str_eq(Nurse->readReport("Test.medicament").c_str(), std::string()
    .c_str());
}

Test(KoalaNurseReadReport, test02)
{
    KoalaNurse *Nurse = new KoalaNurse(14);
    fflush(stdout);
    cr_assert_str_eq(Nurse->readReport("unknown.report").c_str(),
        std::string()
    .c_str());
}

Test(KoalaNurseReadReport, test03)
{
    KoalaNurse *Nurse = new KoalaNurse(14);
    Nurse->readReport("empty.report");
    fflush(stdout);
    cr_assert_str_eq(Nurse->readReport("empty.medicament").c_str(),
        std::string()
    .c_str());
}