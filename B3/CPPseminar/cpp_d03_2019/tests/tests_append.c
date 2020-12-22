/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "../string.h"

Test(string_append, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    append_c(&s, "!");
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
}