/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(RAMModule, creation_test_00, .init=redirect_all_std)
{
    RAMModule test;
}

Test(RAMModule, creation_test_01, .init=redirect_all_std)
{
    RAMModule *test2 = new RAMModule();
    delete test2;
}

Test(RAMModule, refresh_test_00, .init=redirect_all_std)
{
    RAMModule test;
    test.refreshInfoModule();
}

Test(RAMModule, getModuleName_test_00, .init=redirect_all_std)
{
    RAMModule test;
    cr_assert_eq(test.getModuleName(), "RAM");
}

Test(RAMModule, copyConstructor_test_00, .init=redirect_all_std)
{
    RAMModule test;
    RAMModule test2;
    test2 = test;
}

Test(RAMModule, assignmentConstructor_test_00, .init=redirect_all_std)
{
    RAMModule test;
    RAMModule test2 = test;
}