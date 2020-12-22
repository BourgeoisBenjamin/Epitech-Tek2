/*
** EPITECH PROJECT, 2019
** CPP RUSH1
** File description:
** Unit test multiplication
*/

#include "unittest.h"
#include "char.h"
#include "float.h"
#include "int.h"
#include "object.h"

Test(Char_mul, test_char_mul)
{
    Object *a = new(Char, 'a');
    Object *b = new(Char, '\0');
    Object *new = multiplication(a, b);

    cr_assert_eq(((CharClass *)new)->letter, '\0');
}

Test(Int_mul, test_int_mul)
{
    Object *a = new(Int, 2);
    Object *b = new(Int, 4);
    Object *new = multiplication(a, b);

    cr_assert_eq(((IntClass *)new)->nb, 8);
}

Test(Float_mul, test_float_mul)
{
    Object *a = new(Float, 1.0);
    Object *b = new(Float, 42.0);
    Object *new = multiplication(a, b);

    cr_assert_eq(((FloatClass *)new)->nbr, 42.0);
}