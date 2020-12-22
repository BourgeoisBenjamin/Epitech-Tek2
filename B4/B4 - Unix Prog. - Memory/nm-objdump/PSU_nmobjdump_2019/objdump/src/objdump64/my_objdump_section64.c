/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/objdump.h"
#include <ctype.h>

int objdump_is_ignore_section64(elffile64_t *file, int i)
{
    if ((uint32_t)(file->shdr[i].sh_type) == SHT_NOBITS)
        return (1);
    if ((uint32_t)(file->shdr[i].sh_type) == SHT_SYMTAB)
        return (1);
    if ((uint64_t)(file->shdr[i].sh_size) == 0)
        return (1);
    if (strcmp((char*)(file->strtable + file->shdr[i].sh_name), ".rela.text")
        == 0)
        return (1);
    if (strcmp((char*)(file->strtable + file->shdr[i].sh_name), ".rela"
        ".eh_frame") == 0)
        return (1);
    if (strcmp((char*)(file->strtable + file->shdr[i].sh_name), ".strtab") == 0)
        return (1);
    if (strcmp((char*)(file->strtable + file->shdr[i].sh_name), ".shstrtab")
        == 0)
        return (1);
    return (0);
}

void objdump_display_addr64(elffile64_t *file, int i, int j)
{
    for (size_t z = 0; z < 16; z++) {
        if (z + j < file->shdr[i].sh_size)
            printf("%02x", (unsigned char) (((char *) file->data) +
            file->shdr[i].sh_offset)[z + j]);
        else
            printf("  ");
        if (!((z + 1) % 4))
            printf(" ");
    }
    printf(" ");
}

void objdump_display_char64(elffile64_t *file, int i, int j)
{
    for (size_t z = 0; z < 16; z++) {
        char c = (unsigned char)(((char*)file->data)+file->shdr[i].sh_offset)
        [z + j];
        if (z + j < file->shdr[i].sh_size) {
            if (isprint(c))
                printf("%c", c);
            else
                printf(".");
        } else {
            printf(" ");
        }
    }
}

void objdump_display_content_section64(elffile64_t *file, int i)
{
    printf("Contents of section %s:\n", (char*) file->strtable +
    file->shdr[i].sh_name);

    for (size_t j = 0; j < file->shdr[i].sh_size; j += 16) {
        if (file->shdr[i].sh_addr + file->shdr[i].sh_size > 0xffff)
            printf(" %05lx ", file->shdr[i].sh_addr + j);
        else
            printf(" %04lx ", file->shdr[i].sh_addr + j);
        objdump_display_addr64(file, i, j);
        objdump_display_char64(file, i, j);
        printf("\n");
    }
}

void objdump_display_section64(elffile64_t *file)
{
    printf("\n");
    for (int i = 0; i < file->ehdr->e_shnum; i++) {
        if (!objdump_is_ignore_section64(file, i)) {
            objdump_display_content_section64(file, i);
        }
    }
}