/*
** EPITECH PROJECT, 2020
** ftrace
** File description:
** map
*/

#include "map.h"

bool map_contains(list_t map, void *key, bool (*compare)(void *, void *))
{
    list_t iterator = map;
    pair_t *value = NULL;

    while (iterator) {
        value = iterator->value;
        if (compare(key, value->first))
            return (true);
        iterator = iterator->next;
    }
    return (false);
}

void *map_get_value(list_t map, void *key, bool (*compare)(void *, void *))
{
    list_t iterator = map;
    pair_t *value = NULL;

    while (iterator) {
        value = iterator->value;
        if (compare(key, value->first))
            return (value->second);
        iterator = iterator->next;
    }
    return (NULL);
}

bool map_add_value(list_t *map, void *key, void *value)
{
    pair_t *pair = malloc(sizeof(*pair));

    if (!pair)
        return (false);
    pair->first = key;
    pair->second = value;
    list_add_elem_at_back(map, pair);
    return (true);
}

void map_clear(list_t *map, void (*free_pair)(pair_t *pair))
{
    while (list_get_size(*map)) {
        free_pair(list_get_elem_at_front(*map));
        list_del_elem_at_front(map);
    }
}
