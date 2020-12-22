/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"
#include <stddef.h>
#include <stdlib.h>

bool double_btree_create_node(double_btree_t *node_ptr, double value)
{
    doublebtree_node_t *new = NULL;

    new = malloc(sizeof(doublebtree_node_t));
    if (!new) return (false);

    new->value = value;
    new->left = NULL;
    new->right = NULL;
    *node_ptr = new;

    return (true);
}