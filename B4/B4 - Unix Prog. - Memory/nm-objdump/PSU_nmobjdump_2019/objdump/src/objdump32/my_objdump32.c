/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/objdump.h"

void objdump32(elf_t *file)
{
    objdump_display_header32(file->file32);
    objdump_display_section32(file->file32);
}