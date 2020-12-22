/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/objdump.h"

int objdump_is_static_lib(char *filename)
{
    char *ext = strrchr(filename, '.');
    if (!ext)
        return (0);
    if (!strcmp(ext, ".a"))
        return (1);
    return (0);
}

int objdump_process(objdump_t *info, char *filename)
{
    elf_t *file = objdump_init_file();
    if (!file) {
        fprintf(stderr, "%s: '%s': Error with this file\n", info->exec_name,
        filename);
        return (1);
    }
    if (objdump_is_static_lib(filename)) {
        objdump_uninit_file(file);
        return (0);
    }
    if (objdump_init_file_info(info, file, filename) == -1) {
        objdump_uninit_file(file);
        return (1);
    }
    printf("\n");
    file->file64 ? objdump64(file) : objdump32(file);
    objdump_uninit_file(file);
    return (0);
}