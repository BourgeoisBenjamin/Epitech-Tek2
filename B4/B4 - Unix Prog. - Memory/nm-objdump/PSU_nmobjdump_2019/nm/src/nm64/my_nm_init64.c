/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

int nm_init_file64(elf_t *file, char *filename, int fd, void *data)
{
    file->file64 = nm_init_file_struct64();
    if (file->file64 == NULL)
        return (-1);
    if ((fstat(fd, &file->file64->stat)) == -1)
        return (-1);
    file->file64->fd = fd;
    file->file64->filename = filename;
    file->file64->data = data;
    file->file64->ehdr = (Elf64_Ehdr*)file->file64->data;
    file->file64->shdr = (Elf64_Shdr*)(file->file64->data +
    file->file64->ehdr->e_shoff);
    if (nm_format_file(file) == -1)
        return (-1);
    file->file64->strtable = file->file64->data +
    file->file64->shdr[file->file64->ehdr->e_shstrndx].sh_offset;
    return (0);
}

elffile64_t *nm_init_file_struct64(void)
{
    elffile64_t *file = malloc(sizeof(elffile64_t));
    if (!file) {
        return (NULL);
    }
    file->fd = -1;
    file->filename = NULL;
    file->data = NULL;
    file->ehdr = NULL;
    file->shdr = NULL;
    file->strtable = NULL;
    file->symtable = NULL;
    file->strtab = NULL;
    file->list = NULL;
    file->symtable_size = -1;
    file->size_list = 0;
    return (file);
}