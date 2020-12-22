/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"

double double_btree_get_max_value(double_btree_t tree)
{
    double max_value = 0;
    double child_value = 0;

    if (double_btree_is_empty(tree))
        return (0);
    max_value = tree->value;
    child_value = double_btree_get_max_value(tree->right);
    max_value = (max_value > child_value) ? max_value : child_value;
    child_value = double_btree_get_max_value(tree->left);
    max_value = (max_value > child_value) ? max_value : child_value;
    return (max_value);
}