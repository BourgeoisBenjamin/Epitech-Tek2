/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    return (abs(a) + abs(b));
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a,
            operation->add_op.b);
    else
        operation->add_op.res = absolute_add(operation->add_op.a,
            operation->add_op.b);
}