/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(DateModule, creation_test_00, .init=redirect_all_std)
{
    DateModule test;
}

Test(DateModule, creation_test_01, .init=redirect_all_std)
{
    DateModule *test2 = new DateModule();
    delete test2;
}

Test(DateModule, refresh_test_00, .init=redirect_all_std)
{
    DateModule test;
    test.refreshInfoModule();
}

Test(DateModule, getModuleName_test_00, .init=redirect_all_std)
{
    DateModule test;
    cr_assert_eq(test.getModuleName(), "Date");
}

Test(DateModule, copyConstructor_test_00, .init=redirect_all_std)
{
    DateModule test;
    DateModule test2;
    test2 = test;
}

Test(DateModule, assignmentConstructor_test_00, .init=redirect_all_std)
{
    DateModule test;
    DateModule test2 = test;
}

Test(DateModule, getYear_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getYear(), 1900 + local->tm_year);
}

Test(DateModule, getMonth_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getMonth(), local->tm_mon);
}

Test(DateModule, getDay_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getDay(), local->tm_mday);
}

Test(DateModule, getTimeDate_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    DateModule test;
    cr_assert_eq(test.getTimeDate(), std::ctime(&now));
}

Test(DateModule, getHour_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getHour(), local->tm_hour);
}

Test(DateModule, getMinute_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getMinute(), local->tm_min);
}

Test(DateModule, getSecond_test_00, .init=redirect_all_std)
{
    std::time_t now = time(0);
    std::tm *local = localtime(&now);
    DateModule test;
    cr_assert_eq(test.getSecond(), local->tm_sec);
}