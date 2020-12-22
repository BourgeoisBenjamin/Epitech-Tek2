/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(ModulesElements, creation_test_00, .init=redirect_all_std)
{
    ModuleElements test;
}

Test(ModuleElements, creation_test_01, .init=redirect_all_std)
{
    ModuleElements *test2 = new ModuleElements();
    delete test2;
}

Test(ModuleElements, refresh_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.refresh();
}

Test(ModuleElements, getuserM_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.getuserM();
}

Test(ModuleElements, getramM_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.getramM();
}

Test(ModuleElements, getcpuM_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.getcpuM();
}

Test(ModuleElements, getosM_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.getosM();
}

Test(ModuleElements, getdateM_test_00, .init=redirect_all_std)
{
    ModuleElements test;
    test.getdateM();
}