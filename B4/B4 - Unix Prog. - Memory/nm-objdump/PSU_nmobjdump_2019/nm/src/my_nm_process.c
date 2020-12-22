/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/nm.h"

int nm_is_static_lib(char *filename)
{
    char *ext = strrchr(filename, '.');
    if (!ext)
        return (0);
    if (!strcmp(ext, ".a"))
        return (1);
    return (0);
}

int nm_process(nm_t *info, char *filename)
{
    elf_t *file = nm_init_file();
    if (!file) {
        fprintf(stderr, "%s: '%s': Error with this file\n", info->exec_name,
        filename);
        return (1);
    }
    if (nm_is_static_lib(filename)) {
        nm_uninit_file(file);
        return (0);
    }
    if (nm_init_file_info(info, file, filename) == -1) {
        nm_uninit_file(file);
        return (1);
    }
    info->nb_files > 1 ? printf("\n%s:\n", filename) : 0;
    file->file64 ? nm64(file) : nm32(file);
    nm_uninit_file(file);
    return (0);
}