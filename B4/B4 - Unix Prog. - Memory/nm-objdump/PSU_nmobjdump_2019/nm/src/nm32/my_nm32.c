/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

void nm_display32(elffile32_t *file)
{
    for (list_t *tmp = file->list; tmp; tmp = tmp->next) {
        if (tmp->st_info == 'A')
            continue;
        if (tmp->st_info == 'U' || tmp->st_info == 'w')
            printf("         ");
        else
            printf("%08lx ", tmp->value);
        printf("%c ", tmp->st_info);
        printf("%s\n", tmp->name);
    }
}

void nm32(elf_t *file)
{
    nm_save_symbol32(file->file32);
    sort_list(&file->file32->list, file->file32->size_list);
    nm_display32(file->file32);
}