/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "../string.h"

Test(string_at, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    cr_assert_eq(at(&s, 4), 'o');
    string_destroy(&s);
}

Test(string_at, test_01)
{
    string_t s;
    string_init(&s, "Hello World");
    cr_assert_eq(at(&s, -7), -1);
    string_destroy(&s);
}