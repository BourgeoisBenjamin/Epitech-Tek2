/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/objdump.h"

int objdump_is_directory(const char *filename)
{
    struct stat stat_file;

    stat(filename, &stat_file);
    return (S_ISDIR(stat_file.st_mode));
}

int objdump_format_file(elf_t *file)
{
    if (file->file64) {
        if (file->file64->ehdr->e_ident[EI_MAG0] != 0x7f
            || file->file64->ehdr->e_ident[EI_MAG1] != 'E'
            || file->file64->ehdr->e_ident[EI_MAG2] != 'L'
            || file->file64->ehdr->e_ident[EI_MAG3] != 'F')
            return (-1);
        if (file->file64->ehdr->e_type != ET_REL && file->file64->ehdr->e_type
            != ET_EXEC && file->file64->ehdr->e_type != ET_DYN)
            return (-1);
    } else {
        if (file->file32->ehdr->e_ident[EI_MAG0] != 0x7f ||
            file->file32->ehdr->e_ident[EI_MAG1] != 'E' ||
            file->file32->ehdr->e_ident[EI_MAG2] != 'L' ||
            file->file32->ehdr->e_ident[EI_MAG3] != 'F')
            return (-1);
        if (file->file32->ehdr->e_type != ET_REL && file->file32->ehdr->e_type
            != ET_EXEC && file->file32->ehdr->e_type != ET_DYN)
            return (-1);
    }
    return (0);
}