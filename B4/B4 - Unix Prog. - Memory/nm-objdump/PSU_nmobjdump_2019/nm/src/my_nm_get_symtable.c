/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/nm.h"

int nm_get_symtable64(nm_t *info, elffile64_t *file)
{
    for (int i = 0; i < file->ehdr->e_shnum; i++) {
        if (!strcmp(file->strtable + file->shdr[i].sh_name, ".symtab")) {
            file->symtable = (Elf64_Sym *)(file->data + file->shdr[i]
            .sh_offset);
            file->symtable_size = (file->shdr[i].sh_size / sizeof(Elf64_Sym));
        }
        if (!strcmp(file->strtable + file->shdr[i].sh_name, ".strtab"))
            file->strtab = file->data + file->shdr[i].sh_offset;
    }
    if (file->symtable == NULL) {
        fprintf(stderr, "%s: %s: no symbols\n", info->exec_name,
        file->filename);
        return (-1);
    }
    return (0);
}

int nm_get_symtable32(nm_t *info, elffile32_t *file)
{
    for (int i = 0; i < file->ehdr->e_shnum; i++) {
        if (!strcmp(file->strtable + file->shdr[i].sh_name, ".symtab")) {
            file->symtable = (Elf32_Sym *)(file->data + file->shdr[i]
            .sh_offset);
            file->symtable_size = (file->shdr[i].sh_size / sizeof(Elf32_Sym));
        }
        if (!strcmp(file->strtable + file->shdr[i].sh_name, ".strtab"))
            file->strtab = file->data + file->shdr[i].sh_offset;
    }
    if (file->symtable == NULL) {
        fprintf(stderr, "%s: %s: no symbols\n", info->exec_name,
        file->filename);
        return (-1);
    }
    return (0);
}

int nm_get_symtable(nm_t *info, elf_t *file)
{
    if (file->file64)
        return (nm_get_symtable64(info, file->file64));
    return (nm_get_symtable32(info, file->file32));
}