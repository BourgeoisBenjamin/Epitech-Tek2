/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/objdump.h"

void objdump64(elf_t *file)
{
    objdump_display_header64(file->file64);
    objdump_display_section64(file->file64);
}