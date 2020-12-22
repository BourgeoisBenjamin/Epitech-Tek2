/*
** EPITECH PROJECT, 2019
** CPP RUSH1
** File description:
** Unit test new
*/

#include "unittest.h"

Test(new, test01)
{
    cr_assert_neq(new(Player), NULL);
}

Test(new, test_iscrashing)
{
    cr_assert_neq(new(Point, ' '), NULL);
    cr_assert_neq(new(Point, "bonjour"), NULL);
    cr_assert_neq(new(Vertex, ' '), NULL);
    cr_assert_neq(new(Vertex, "bonjour"), NULL);
    cr_assert_neq(new(Point), NULL);
    cr_assert_neq(new(Vertex), NULL);
    cr_assert_neq(new(Point, NULL), NULL);
    cr_assert_neq(new(Vertex, NULL), NULL);
}

Test(new, test_save_value)
{
    Object *var_point = new(Point, 2, 5);
    Object *var_vertex = new(Vertex, 2, 5, 10);

    cr_assert_eq(((PointClass *)var_point)->x, 2);
    cr_assert_eq(((PointClass *)var_point)->y, 5);
    cr_assert_eq(((VertexClass *)var_vertex)->x, 2);
    cr_assert_eq(((VertexClass *)var_vertex)->y, 5);
    cr_assert_eq(((VertexClass *)var_vertex)->z, 10);
}