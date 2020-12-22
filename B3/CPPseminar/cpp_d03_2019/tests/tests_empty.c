/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "../string.h"

Test(string_empty, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    cr_assert_eq(empty(&s), 0);
    string_destroy(&s);
}

Test(string_empty, test_01)
{
    string_t s;
    string_init(&s, "Hello World");
    clear(&s);
    cr_assert_eq(empty(&s), 1);
    string_destroy(&s);
}