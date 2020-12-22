/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "int.h"
#include "float.h"
#include "char.h"

Test(ft_eq_int, test01)
{
    Object *int1 = new(Int, 32);
    Object *int2 = new(Int, 8);

    cr_expect_eq(eq(int1, int2), 0);
}

Test(ft_eq_int, test02)
{
    Object *int1 = new(Int, -32);
    Object *int2 = new(Int, -32);

    cr_expect_eq(eq(int1, int2), 1);
}

Test(ft_eq_float, test01)
{
    Object *float1 = new(Float, 32.3);
    Object *float2 = new(Float, 8.3);

    cr_expect_eq(eq(float1, float2), 0);
}

Test(ft_eq_float, test02)
{
    Object *float1 = new(Float, 32.3);
    Object *float2 = new(Float, 32.3);

    cr_expect_eq(eq(float1, float2), 1);
}

Test(ft_eq_char, test01)
{
    Object *char1 = new(Int, 'a');
    Object *char2 = new(Int, 'A');

    cr_expect_eq(eq(char1, char2), 0);
}

Test(ft_eq_char, test02)
{
    Object *char1 = new(Char, 'a');
    Object *char2 = new(Char, 'a');

    cr_expect_eq(eq(char1, char2), 1);
}