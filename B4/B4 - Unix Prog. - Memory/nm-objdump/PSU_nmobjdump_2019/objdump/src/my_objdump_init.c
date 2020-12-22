/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/objdump.h"

objdump_t *init_objdump(char **argv)
{
    objdump_t *new = malloc(sizeof(objdump_t));
    if (!new)
        return (NULL);
    new->exec_name = argv[0];
    new->files = &argv[1];
    return (new);
}

elf_t *objdump_init_file(void)
{
    elf_t *new = malloc(sizeof(elf_t));
    if (!new)
        return (NULL);
    new->file32 = NULL;
    new->file64 = NULL;
    return (new);
}

int objdump_file_truncated(elf_t *file)
{
    (void)file;
    size_t th_size = 0;
    size_t re_size = file->file64 ? file->file64->stat.st_size :
    file->file32->stat.st_size;
    th_size = file->file64 ? (file->file64->ehdr->e_shnum
* file->file64->ehdr->e_shentsize) : (file->file32->ehdr->e_shnum
    * file->file32->ehdr->e_shentsize);
    th_size += file->file64 ? file->file64->ehdr->e_shoff :
    file->file32->ehdr->e_shoff;
    return (th_size < re_size);
}

int objdump_init_file_info(objdump_t *info, elf_t *file, char *filename)
{
    int fd = -1;
    if (objdump_is_directory(filename)) {
        fprintf(stderr, "%s: Warning: '%s' is a directory\n",
        info->exec_name, filename);
        return (-1);
    } else if ((fd = objdump_open_file(filename)) == -1) {
        fprintf(stderr, "%s: '%s': No such file\n", info->exec_name,
        filename);
        return (-1);
    }
    if (objdump_init_32_64(file, filename, fd) == -1) {
        fprintf(stderr, "%s: %s: file format not recognized\n",
        info->exec_name, filename);
        return (-1);
    } else if (objdump_file_truncated(file)) {
        fprintf(stderr, "%s: %s: file truncated\n", info->exec_name, filename);
        return (-1);
    }
    return (0);
}

int objdump_init_32_64(elf_t *file, char *filename, int fd)
{
    struct stat stat;
    void *data = NULL;
    Elf64_Ehdr *ehdr;

    if ((fstat(fd, &stat)) == -1)
        return (-1);
    if ((data = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
        MAP_FAILED)
        return (-1);

    ehdr = (Elf64_Ehdr*)data;

    if (ehdr->e_ident[EI_CLASS] == ELFCLASS64)
        return (objdump_init_file64(file, filename, fd, data));
    else
        return (objdump_init_file32(file, filename, fd, data));
}