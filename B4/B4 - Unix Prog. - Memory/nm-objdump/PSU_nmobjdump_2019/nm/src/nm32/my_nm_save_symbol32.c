/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

unsigned char nm_get_symbol32_2(elffile32_t *file, int i, int local)
{
    if ((file->shdr[file->symtable[i].st_shndx].sh_type == SHT_PROGBITS &&
        file->shdr[file->symtable[i].st_shndx].sh_flags == (SHF_ALLOC |
        SHF_EXECINSTR)) || ((file->shdr[file->symtable[i].st_shndx].sh_type
        == SHT_INIT_ARRAY || file->shdr[file->symtable[i].st_shndx].sh_type
        == SHT_FINI_ARRAY) && file->shdr[file->symtable[i].st_shndx]
        .sh_flags == (SHF_ALLOC | SHF_WRITE)))
        return ('T' + local);
    if (ELF64_ST_BIND(file->symtable[i].st_info) == STB_WEAK
        && ELF64_ST_TYPE(file->symtable[i].st_info) == STT_OBJECT)
        return ('V' + local);
    if (file->symtable[i].st_shndx == SHN_UNDEF)
        return ('U');
    if (ELF32_ST_BIND(file->symtable[i].st_info) == STB_GNU_UNIQUE)
        return ('u');
    return ('?');
}

unsigned char nm_get_symbol32(elffile32_t *file, int i)
{
    int local = (ELF32_ST_BIND(file->symtable[i].st_info) == STB_LOCAL) ? 32
: 0;
    if (ELF32_ST_BIND(file->symtable[i].st_info) == STB_WEAK)
        return ((file->symtable[i].st_shndx == SHN_UNDEF) ? 'w' : 'W');
    if (file->symtable[i].st_shndx == SHN_ABS)
        return ('A');
    if (file->shdr[file->symtable[i].st_shndx].sh_type == SHT_NOBITS &&
        file->shdr[file->symtable[i].st_shndx].sh_flags == (SHF_ALLOC |
        SHF_WRITE))
        return ('B' + local);
    if (file->symtable[i].st_shndx == SHN_COMMON) return ('C');
    if (((file->shdr[file->symtable[i].st_shndx].sh_type == SHT_PROGBITS ||
        file->shdr[file->symtable[i].st_shndx].sh_type == SHT_DYNAMIC) &&
        file->shdr[file->symtable[i].st_shndx].sh_flags == (SHF_ALLOC |
        SHF_WRITE)))
        return ('D' + local);
    if (file->shdr[file->symtable[i].st_shndx].sh_type == SHT_PROGBITS &&
        file->shdr[file->symtable[i].st_shndx].sh_flags == SHF_ALLOC)
        return ('R' + local);
    return (nm_get_symbol32_2(file, i, local));
}

void nm_add_symbol32(elffile32_t *file, int i)
{
    list_t *new = nm_create_node();
    if (!new)
        return;
    new->name = &file->strtab[file->symtable[i].st_name];
    new->value = file->symtable[i].st_value;
    new->size = (uint64_t)(file->symtable[i].st_size);
    new->st_info = nm_get_symbol32(file, i);
    file->list = nm_add_in_list(file->list, new);
    file->size_list += 1;
}

int nm_save_symbol32(elffile32_t *file)
{
    for (int i = 0; i < file->symtable_size; i++) {
        if (!(&file->strtab[file->symtable[i].st_name])[0])
            continue;
        nm_add_symbol32(file, i);
    }
    return (0);
}