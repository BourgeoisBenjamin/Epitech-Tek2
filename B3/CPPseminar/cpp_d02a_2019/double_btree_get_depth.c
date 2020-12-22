/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"

unsigned int double_btree_get_depth(double_btree_t tree)
{
    unsigned int depth = 0;
    unsigned int depth_right = 0;
    unsigned int depth_left = 0;

    if (double_btree_is_empty(tree))
        return (0);

    depth_right = double_btree_get_size(tree->right);
    depth_left = double_btree_get_size(tree->left);
    depth = (depth_right > depth_left) ? depth_right : depth_left;

    return (depth);
}