/*
** EPITECH PROJECT, 2019
** CPP RUSH1
** File description:
** Unit test new
*/

#include "include/unittest.h"
#include "../char.h"
#include "../int.h"
#include "../float.h"

static Object *Char_sub(const Object *self, const Object *other);
static Object *Int_sub(const Object *self, const Object *other);
static Object *Float_sub(const Object *self, const Object *other);
static Object *Vertex_add(const Object *self, const Object *other);
static Object *Vertex_sub(const Object *self, const Object *other);
static Object *Point_sub(const Object *self, const Object *other);

Test(Char_sub, test00)
{
    Object *self = new(Char, 'a');
    Object *other = new(Char, '-');
    Object *res = subtraction(self, other);

    cr_assert_eq(((CharClass *)res)->letter, '4');
}

Test(Int_sub, test01)
{
    Object *self = new(Int, 42);
    Object *other = new(Int, 2);
    Object *res = subtraction(self, other);

    cr_assert_eq(((IntClass *)res)->nb, 40);
}

Test(Float_sub, test02)
{
    Object *self = new(Float, 42.5);
    Object *other = new(Float, 2.0);
    Object *res = subtraction(self, other);

    cr_expect_eq(((FloatClass *)res)->nbr, 40.5);
    self = new(Float, 42.0);
    other = new(Float, 2.0);
    res = subtraction(self, other);
    cr_assert_eq(((FloatClass *)res)->nbr, 40.0);
}

Test(Vertex_sub, test03)
{
    Object *self = new(Int, 42);
    Object *other = new(Int, 2);
    Object *res = subtraction(self, other);

    cr_expect_eq(((IntClass *)res)->nb, 40);
}

Test(Point_sub, test05)
{
    Object *self = new(Int, 1, 2, 4);
    Object *other = new(Int, 1, 2, 3);
    Object *res = subtraction(self, other);

    cr_expect_eq(((IntClass *)res)->nb, 0);
}