/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

void nm_display64(elffile64_t *file)
{
    for (list_t *tmp = file->list; tmp; tmp = tmp->next) {
        if (tmp->st_info == 'A')
            continue;
        if (tmp->st_info == 'U' || tmp->st_info == 'w')
            printf("                 ");
        else
            printf("%016lx ", tmp->value);
        printf("%c ", tmp->st_info);
        printf("%s\n", tmp->name);
    }
}

void nm64(elf_t *file)
{
    nm_save_symbol64(file->file64);
    sort_list(&file->file64->list, file->file64->size_list);
    nm_display64(file->file64);
}