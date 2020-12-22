/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "../string.h"
#include "unittest.h"

Test(string_insert, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    insert_c(&s, 0, "BON");
    cr_assert_str_eq(s.str, "BONHello World");
    string_destroy(&s);
}