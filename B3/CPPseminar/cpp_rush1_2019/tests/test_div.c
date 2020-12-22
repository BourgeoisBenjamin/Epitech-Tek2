/*
** EPITECH PROJECT, 2019
** CPP RUSH1
** File description:
** Unit test new
*/

#include "unittest.h"
#include "char.h"
#include "int.h"
#include "float.h"
#include "object.h"

//div char int float

Test(Char_div, test_char_div)
{
    Object *a = new(Char, 'A');
    Object *b = new(Char, 1);
    Object *new = division(a, b);
    cr_assert_eq(((CharClass *)new)->letter, 'A');
}

Test(Char_int, test_int_div)
{
    Object *a = new(Int, 10);
    Object *b = new(Int, 2);
    Object *new = division(a, b);
    cr_assert_eq(((IntClass *)new)->nb, 5);
}

Test(Char_float, test_float_div)
{
    Object *a = new(Float, 10.0);
    Object *b = new(Float, 2.0);
    Object *new = division(a, b);
    cr_assert_eq(((FloatClass *)new)->nbr, 5.0);
}