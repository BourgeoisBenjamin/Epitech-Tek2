/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "../string.h"

Test(string_clear, test_00)
{
    string_t s;
    string_init(&s, "Hello World");
    clear(&s);
    cr_assume_null(s.str);
    string_destroy(&s);
}