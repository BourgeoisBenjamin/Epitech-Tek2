/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(CPUModule, creation_test_00, .init=redirect_all_std)
{
    CPUModule test;
}

Test(CPUModule, creation_test_01, .init=redirect_all_std)
{
    CPUModule *test2 = new CPUModule();
    delete test2;
}

Test(CPUModule, refresh_test_00, .init=redirect_all_std)
{
    CPUModule test;
    test.refreshInfoModule();
}

Test(CPUModule, getModuleName_test_00, .init=redirect_all_std)
{
    CPUModule test;
    cr_assert_eq(test.getModuleName(), "CPU");
}

Test(CPUModule, copyConstructor_test_00, .init=redirect_all_std)
{
    CPUModule test;
    CPUModule test2;
    test2 = test;
}

Test(CPUModule, assignmentConstructor_test_00, .init=redirect_all_std)
{
    CPUModule test;
    CPUModule test2 = test;
}