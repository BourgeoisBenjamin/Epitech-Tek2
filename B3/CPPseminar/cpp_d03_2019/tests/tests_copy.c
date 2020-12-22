/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "../string.h"

Test(string_copy, test_00)
{
    string_t s;
    char buffer[10];
    buffer[3] = 0;
    string_init(&s, "H");
    cr_assert_eq(copy(&s, buffer, 1, 0), 1);
    cr_assert_str_eq(buffer, "H");
    string_destroy(&s);
}

Test(string_copy, test_01)
{
    string_t s;
    char buffer[10];
    buffer[3] = 0;
    string_init(&s, "H");
    cr_assert_eq(copy(&s, buffer, 2, 0), 2);
    cr_assert_str_eq(buffer, "H");
    string_destroy(&s);
}