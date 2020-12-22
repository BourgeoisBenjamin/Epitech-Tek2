/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#ifndef PSU_NMOBJDUMP_2019_NM_H
#define PSU_NMOBJDUMP_2019_NM_H

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

typedef struct list_s
{
    char *name;
    unsigned char st_info;
    size_t value;
    uint64_t size;
    struct list_s *next;
} list_t;

typedef struct elffile64_s
{
    char *filename;
    int fd;
    void *data;
    void *strtable;
    struct stat stat;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *symtable;
    char *strtab;
    int symtable_size;
    list_t *list;
    int size_list;
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
    Elf32_Sym *symtable;
    char *strtab;
    int symtable_size;
    list_t *list;
    int size_list;
} elffile32_t;

typedef struct elf_s
{
    elffile64_t *file64;
    elffile32_t *file32;
} elf_t;

typedef struct nm_s
{
    char *exec_name;
    char **files;
    int nb_files;
} nm_t;

/* MAIN FUNCTION */
int my_nm(int argc, char **argv);
int nm_process(nm_t *info, char *filename);
int nm_is_static_lib(char *filename);
void nm32(elf_t *file);
void nm64(elf_t *file);

/* INIT FUNCTION */
nm_t *init_nm(int argc, char **argv);
elf_t *nm_init_file(void);
int nm_open_file(const char *file);
int nm_init_file_info(nm_t *info, elf_t *file, char *filename);
int nm_init_32_64(elf_t *file, char *filename, int fd);
int nm_get_symtable(nm_t *info, elf_t *file);

/* 32 BITS */
int nm_init_file32(elf_t *file, char *filename, int fd, void *data);
elffile32_t *nm_init_file_struct32(void);
int nm_get_symtable32(nm_t *info, elffile32_t *file);
unsigned char nm_get_symbol32(elffile32_t *file, int i);
unsigned char nm_get_symbol32_2(elffile32_t *file, int i, int local);
void nm_add_symbol32(elffile32_t *file, int i);
int nm_save_symbol32(elffile32_t *file);

/* 64 BITS */
int nm_init_file64(elf_t *file, char *filename, int fd, void *data);
elffile64_t *nm_init_file_struct64(void);
int nm_get_symtable64(nm_t *info, elffile64_t *file);
unsigned char nm_get_symbol64(elffile64_t *file, int i);
unsigned char nm_get_symbol64_2(elffile64_t *file, int i, int local);
int nm_save_symbol64(elffile64_t *file);
void nm_add_symbol64(elffile64_t *file, int i);

/* ERROR FUNCTION */
int nm_is_directory(const char *filename);
int nm_format_file(elf_t *file);
int nm_file_truncated(elf_t *file);

/* FREE FUNCTION */
void nm_uninit_file(elf_t *file);

/* LIST */
list_t *nm_create_node(void);
list_t *nm_add_in_list(list_t *list, list_t *new);
void nm_delete_list(list_t *list);
int compare_name(char *str1, char *str2);
list_t* swap(list_t* ptr1, list_t* ptr2);
int sort_list(list_t **list_head, int size);

#endif //PSU_NMOBJDUMP_2019_NM_H
