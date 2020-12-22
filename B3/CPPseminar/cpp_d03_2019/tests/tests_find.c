/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "../string.h"
#include "unittest.h"

Test(string_find, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    cr_assert_eq(find_c(&s, "llo", 0), 2);
    string_destroy(&s);
}