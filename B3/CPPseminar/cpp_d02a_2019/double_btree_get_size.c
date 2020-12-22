/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"

unsigned int double_btree_get_size(double_btree_t tree)
{
    if (double_btree_is_empty(tree)) return (0);
    return (1 + double_btree_get_size(tree->right) + double_btree_get_size
    (tree->left));
}