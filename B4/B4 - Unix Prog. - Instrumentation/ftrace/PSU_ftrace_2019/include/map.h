/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "linked_list/generic_list.h"
#include <stdlib.h>

typedef struct {
    void *first;
    void *second;
} pair_t;

bool map_contains(list_t map, void *key, bool (*compare)(void *, void *));
bool map_add_value(list_t *map, void *key, void *value);
void map_clear(list_t *map, void (*free_pair)(pair_t *pair));

#endif /* !MAP_H_ */
