/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(OSModule, creation_test_00, .init=redirect_all_std)
{
    OSModule test;
}

Test(OSModule, creation_test_01, .init=redirect_all_std)
{
    OSModule *test2 = new OSModule();
    delete test2;
}

Test(OSModule, refresh_test_00, .init=redirect_all_std)
{
    OSModule test;
    test.refreshInfoModule();
}

Test(OSModule, getModuleName_test_00, .init=redirect_all_std)
{
    OSModule test;
    cr_assert_eq(test.getModuleName(), "OS");
}

Test(OSModule, copyConstructor_test_00, .init=redirect_all_std)
{
    OSModule test;
    OSModule test2;
    test2 = test;
}

Test(OSModule, assignmentConstructor_test_00, .init=redirect_all_std)
{
    OSModule test;
    OSModule test2 = test;
}