/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Droid, general_test, .init=redirect_all_std)
{
    if (1) {
        Droid d;
        Droid d1("Avenger");
        size_t Durasel = 200;
        std::cout << d << std::endl;
        std::cout << d1 << std::endl;
        d = d1;
        d.setStatus(new std::string("Kill Kill Kill!"));
        d << Durasel;
        std::cout << d << "--" << Durasel << std::endl;
        Droid d2 = d;
        d.setId("Rex");
        std::cout << (d2 != d) << std::endl;
    }
    cr_assert_stdout_eq_str("Droid '' Activated\n"
        "Droid 'Avenger' Activated\n"
        "Droid '', Standing by, 50\n"
        "Droid 'Avenger', Standing by, 50\n"
        "Droid 'Avenger', Kill Kill Kill!, 100--150\n"
        "Droid 'Avenger' Activated, Memory Dumped\n"
        "1\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Rex' Destroyed\n");
}

Test(Droid, test00, .init=redirect_all_std)
{
    if (1) {
        Droid d;
        size_t duracel = 50;
        cr_assert_eq(d.getAttack(), 25);
        cr_assert_eq(d.getEnergy(), 50);
        cr_assert_eq(d.getToughness(), 15);
        cr_assert_str_eq((*d.getStatus()).c_str(), "Standing by");
        d.setEnergy(6);
        cr_assert_eq(d.getEnergy(), 6);
        d.setEnergy(150);
        cr_assert_eq(d.getEnergy(), 100);
        d.setEnergy(49);
        d << duracel;
        cr_assert_eq(d.getEnergy(), 99);
    }
}

Test(Droid, test01, .init=redirect_all_std)
{
    if (1) {
        Droid d;
        Droid d1;
        cr_assert_eq(d == d1, true);
    }
}