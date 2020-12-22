/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/objdump.h"

int objdump_init_file32(elf_t *file, char *filename, int fd, void *data)
{
    file->file32 = objdump_init_file_struct32();
    if (file->file32 == NULL)
        return (-1);
    if ((fstat(fd, &file->file32->stat)) == -1)
        return (-1);
    file->file32->fd = fd;
    file->file32->filename = filename;
    file->file32->data = data;
    file->file32->ehdr = (Elf32_Ehdr*)file->file32->data;
    file->file32->shdr = (Elf32_Shdr*)(file->file32->data +
    file->file32->ehdr->e_shoff);
    if (objdump_format_file(file) == -1)
        return (-1);
    file->file32->strtable = file->file32->data +
    file->file32->shdr[file->file32->ehdr->e_shstrndx].sh_offset;
    return (0);
}

elffile32_t *objdump_init_file_struct32(void)
{
    elffile32_t *file = malloc(sizeof(elffile32_t));
    if (!file) {
        return (NULL);
    }
    file->fd = -1;
    file->filename = NULL;
    file->data = NULL;
    file->ehdr = NULL;
    file->shdr = NULL;
    file->strtable = NULL;
    return (file);
}