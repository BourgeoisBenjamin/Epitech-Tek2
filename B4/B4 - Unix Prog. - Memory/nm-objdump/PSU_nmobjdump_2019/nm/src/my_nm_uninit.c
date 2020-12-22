/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/nm.h"

void nm_uninit_file(elf_t *file)
{
    if (!file)
        return;
    if (file->file32) {
        close(file->file32->fd);
        munmap(file->file32->data, file->file32->stat.st_size);
        nm_delete_list(file->file32->list);
        free(file->file32);
    } else if (file->file64) {
        close(file->file64->fd);
        munmap(file->file64->data, file->file64->stat.st_size);
        nm_delete_list(file->file64->list);
        free(file->file64);
    }
    free(file);
}