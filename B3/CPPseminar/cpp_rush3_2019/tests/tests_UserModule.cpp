/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(UserModule, creation_test_00, .init=redirect_all_std)
{
    UserModule test;
}

Test(UserModule, creation_test_01, .init=redirect_all_std)
{
    UserModule *test2 = new UserModule();
    delete test2;
}

Test(UserModule, refresh_test_00, .init=redirect_all_std)
{
    UserModule test;
    test.refreshInfoModule();
}

Test(UserModule, getModuleName_test_00, .init=redirect_all_std)
{
    UserModule test;
    cr_assert_eq(test.getModuleName(), "User");
}

Test(UserModule, copyConstructor_test_00, .init=redirect_all_std)
{
    UserModule test;
    UserModule test2;
    test2 = test;
}

Test(UserModule, assignmentConstructor_test_00, .init=redirect_all_std)
{
    UserModule test;
    UserModule test2 = test;
}

Test(UserModule, getHome_test_00, .init=redirect_all_std)
{
    UserModule test;
    cr_assert_eq(test.getHome(), std::getenv("HOME"));
}

Test(UserModule, getUsername_test_00, .init=redirect_all_std)
{
    UserModule test;
    cr_assert_eq(test.getUsername(), std::getenv("USER"));
}

Test(UserModule, getHostname_test_00, .init=redirect_all_std)
{
    UserModule test;
    cr_assert_eq(test.getHostname(), std::getenv("HOSTNAME"));
}