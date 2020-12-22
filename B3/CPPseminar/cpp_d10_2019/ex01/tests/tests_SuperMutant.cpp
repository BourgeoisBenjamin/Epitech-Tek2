/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(ASuperMutant, creation, .init=redirect_all_std)
{
    if (1)
        SuperMutant test;
    cr_assert_stdout_eq_str("Gaaah. Me want smash heads!\n"
                            "Aaargh...\n");
}

Test(ASuperMutant, getType, .init=redirect_all_std)
{
    if (1) {
        SuperMutant test;
        cr_assert_eq(test.getType(), "Super Mutant");
    }
}

Test(ASuperMutant, getHP, .init=redirect_all_std)
{
    if (1) {
        SuperMutant test;
        cr_assert_eq(test.getHP(), 170);
    }
}

Test(ASuperMutant, takeDamage, .init=redirect_all_std)
{
    if (1) {
        SuperMutant test;
        test.takeDamage(6);
        cr_assert_eq(test.getHP(), 167);
    }
}