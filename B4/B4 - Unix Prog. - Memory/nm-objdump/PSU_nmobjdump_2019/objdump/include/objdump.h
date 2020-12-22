/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#ifndef PSU_NMOBJDUMP_2019_OBJDUMP_H
#define PSU_NMOBJDUMP_2019_OBJDUMP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include "flags.h"

typedef struct emachine_s
{
    uint16_t identifier;
    char *name;
} emachine_t;

typedef struct eflags_s
{
    uint32_t identifier;
    char *name;
} eflags_t;

typedef struct elffile64_s
{
    char *filename;
    int fd;
    void *data;
    void *strtable;
    struct stat stat;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
} elffile64_t;

typedef struct elffile32_s
{
    char *filename;
    int fd;
    void *data;
    void *strtable;
    struct stat stat;
    Elf32_Ehdr *ehdr;
    Elf32_Shdr *shdr;
} elffile32_t;

typedef struct elf_s
{
    elffile64_t *file64;
    elffile32_t *file32;
} elf_t;

typedef struct objdump_s
{
    char *exec_name;
    char **files;
} objdump_t;

/* MAIN FUNCTION */
int my_objdump(char **argv);

/* CORE FUNCTION */
int objdump_process(objdump_t *info, char *filename);
int objdump_is_static_lib(char *filename);
void objdump64(elf_t *file);
void objdump32(elf_t *file);

/* INIT FUNCTION */
int objdump_open_file(const char *file);
elf_t *objdump_init_file(void);
objdump_t *init_objdump(char **argv);
int objdump_init_file_info(objdump_t *info, elf_t *file, char *filename);
int objdump_init_32_64(elf_t *file, char *filename, int fd);
int objdump_init_file64(elf_t *file, char *filename, int fd, void *data);
int objdump_init_file32(elf_t *file, char *filename, int fd, void *data);
elffile32_t *objdump_init_file_struct32(void);
elffile64_t *objdump_init_file_struct64(void);

/* UNINIT FUNCTION */
void objdump_uninit_file(elf_t *file);

/* ERROR FUNCTION */
int objdump_format_file(elf_t *file);
int objdump_is_directory(const char *filename);
int objdump_file_truncated(elf_t *file);

/* HEADER FUNCTION */
char *objdump_get_architecture64(uint16_t identifier);
uint32_t get_flags64(elffile64_t *file);
void objdump_print_flags64(uint32_t e_flags);
void objdump_display_header64(elffile64_t *file);

char *objdump_get_architecture32(uint16_t identifier);
uint32_t get_flags32(elffile32_t *file);
void objdump_print_flags32(uint32_t e_flags);
void objdump_display_header32(elffile32_t *file);

int objdump_is_ignore_section64(elffile64_t *file, int i);
void objdump_display_content_section64(elffile64_t *file, int i);
void objdump_display_section64(elffile64_t *file);

int objdump_is_ignore_section32(elffile32_t *file, int i);
void objdump_display_addr32(elffile32_t *file, int i, int j);
void objdump_display_char32(elffile32_t *file, int i, int j);
void objdump_display_content_section32(elffile32_t *file, int i);
void objdump_display_section32(elffile32_t *file);


#endif //PSU_NMOBJDUMP_2019_OBJDUMP_H
