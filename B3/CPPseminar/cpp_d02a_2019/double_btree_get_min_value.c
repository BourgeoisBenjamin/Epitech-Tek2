/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"

double double_btree_get_min_value(double_btree_t tree)
{
    double min_value = 0.0;
    double childr_value = 0.0;
    double childl_value = 0.0;
    static int empty = 0;

    if (double_btree_is_empty(tree) && !empty)
        return (0.0);
    else if (double_btree_is_empty(tree) && empty)
        return (9999999.9);
    empty = 1;
    min_value = tree->value;
    childr_value = double_btree_get_min_value(tree->right);
    childl_value = double_btree_get_min_value(tree->left);

    if (min_value <= childr_value && min_value <= childl_value)
        return (min_value);
    else if (childr_value <= min_value && childr_value <= childl_value)
        return (childr_value);
    else
        return (childl_value);
}