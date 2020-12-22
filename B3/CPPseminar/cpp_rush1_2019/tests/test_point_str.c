/*
** EPITECH PROJECT, 2019
** CCP RUSH1
** File description:
** Unit test point_str
*/

#include "unittest.h"

Test(point_str, test_print, .init = redirect_all_std )
{
    Object *point = new(Point, 42, -42);
    Object *vertex = new(Vertex, 0, 1, 2);

    printf("point = %s\n", str(point));
    printf("vertex = %s\n", str(vertex));

    fflush(stdout);
    cr_assert_stdout_eq_str("point = <Point (42, -42)>\n"\
    "vertex = <Vertex (0, 1, 2)>\n");
}