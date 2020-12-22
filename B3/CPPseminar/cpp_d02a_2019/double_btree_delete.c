/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"
#include <stdlib.h>

bool double_btree_delete(double_btree_t *root_ptr)
{
    if (double_btree_is_empty(*root_ptr)) {
        *root_ptr = NULL;
        return (false);
    }
    if ((*root_ptr)->right)
        double_btree_delete(&(*root_ptr)->right);
    if ((*root_ptr)->left)
        double_btree_delete(&(*root_ptr)->left);
    free(*root_ptr);
    *root_ptr = NULL;
    return (true);
}