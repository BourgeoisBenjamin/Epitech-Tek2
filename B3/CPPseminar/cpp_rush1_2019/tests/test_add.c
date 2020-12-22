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

static Object *Char_add(const Object *self, const Object *other);
static Object *Float_add(const Object *self, const Object *other);
static Object *Int_add(const Object *self, const Object *other);
static Object *Vertex_add(const Object *self, const Object *other);
static Object *Point_add(const Object *self, const Object *other);

Test(Char_add, test00)
{
    Object *self = new(Char, '+');
    Object *other = new(Char, '+');
    Object *res = addition(self, other);

    cr_expect_eq(((CharClass *)res)->letter, 'V');
}

static Object *Int_add(const Object *self, const Object *other);

Test(Int_add, test01)
{
    Object *self = new(Int, 42);
    Object *other = new(Int, 2);
    Object *res = addition(self, other);

    cr_expect_eq(((IntClass *)res)->nb, 44);
}

Test(Float_add, test02)
{
    Object *self = new(Float, 42.5);
    Object *other = new(Float, 2.0);
    Object *res = addition(self, other);

    cr_expect_float_eq(((FloatClass *)res)->nbr, 44,5);
    /* self = new(Int, 42);
    other = new(Int, 2);
    cr_expect_eq(((FloatClass *)res)->nbr, 44); */
}

Test(Vertex_add, test03)
{
    Object *self = new(Int, 42);
    Object *other = new(Int, 2);
    Object *res = addition(self, other);

    cr_expect_eq(((IntClass *)res)->nb, 44);
}

Test(Point_add, test05)
{
    Object *self = new(Int, 1, 2, 4);
    Object *other = new(Int, 1, 2, 3);
    Object *res = addition(self, other);

    cr_expect_eq(((IntClass *)res)->nb, 2);
}