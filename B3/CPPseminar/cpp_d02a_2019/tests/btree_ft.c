/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_btree.h"
#include <stddef.h>
#include <stdio.h>

void btree_populate_left(double_btree_t tree)
{
    double_btree_t left_sub_tree = tree->left;
    double_btree_create_node(&(left_sub_tree->left), 30);
    double_btree_create_node(&(left_sub_tree->right), 5);
}

void btree_populate_tree(double_btree_t *tree)
{
    double_btree_create_node(tree, 42.5);
    double_btree_create_node(&((*tree)->right), 100);
    double_btree_create_node(&((*tree)->left), 20);
    btree_populate_left(*tree);
}

void btree_test_size(double_btree_t tree)
{
    unsigned int size = double_btree_get_size(tree);
    unsigned int depth = double_btree_get_depth(tree);
    printf("The tree's size is %u\n", size);
    printf("The tree's depth is %u\n", depth);
}

void btree_test_values(double_btree_t tree)
{
    double max = double_btree_get_max_value(tree);
    double min = double_btree_get_min_value(tree);
    printf("The tree's values range from %f to %f\n", min, max);
}

void btree_final_test(double_btree_t tree)
{
    if (!double_btree_is_empty(tree))
        printf("List is not empty\n");
    double_btree_delete(&tree);
    if (double_btree_is_empty(tree))
        printf("List is empty\n");
    double_btree_delete(&tree);
}