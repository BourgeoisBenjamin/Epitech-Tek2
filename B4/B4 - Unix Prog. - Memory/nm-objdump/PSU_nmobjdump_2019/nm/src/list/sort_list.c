/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

list_t* swap(list_t* ptr1, list_t* ptr2)
{
    list_t* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return (ptr2);
}

int sort_list(list_t **list_head, int size)
{
    list_t** head = NULL;
    int swapped = 0;

    for (int i = 0; i <= size; i++) {
        head = list_head;
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            list_t* p1 = *head;
            list_t* p2 = p1->next;
            if (compare_name(p1->name, p2->name) > 0) {
                *head = swap(p1, p2);
                swapped = 1;
            }
            head = &(*head)->next;
        }
        if (swapped == 0)
            break;
    }
    return (0);
}