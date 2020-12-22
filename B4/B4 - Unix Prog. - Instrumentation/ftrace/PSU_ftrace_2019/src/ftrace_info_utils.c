/*
** EPITECH PROJECT, 2020
** ftrace
** File description:
** ftrace info utils
*/

#include "ftrace.h"

static char *get_binary_name(const char *filepath)
{
    int i = strlen(filepath) - 1;
    int a = 0;
    char *name = calloc(1, i + 2);

    if (!name)
        return (NULL);
    for (; i != -1 && filepath[i] != '/'; i--);
    i++;
    for (; filepath[i]; i++, a++)
        name[a] = filepath[i];
    return (name);
}

ftrace_info_t *ftrace_info_init(const char *filepath)
{
    ftrace_info_t *info = malloc(sizeof(ftrace_info_t));

    if (!info)
        return (NULL);
    *info = (ftrace_info_t){0};
    info->child_pid = 0;
    info->name = get_binary_name(filepath);
    info->fd = find_and_open_file(filepath);
    if (info->fd == -1 || !info->name)
        return (NULL);
    elf_version(EV_CURRENT);
    info->elf = elf_begin(info->fd, ELF_C_READ, NULL);
    find_symbol_table(info->elf, &info->elf_shdr, &info->elf_scn);
    return (info);
}

void ftrace_info_delete(ftrace_info_t *to_delete)
{
    if (to_delete->fct_stack)
        list_clear(&to_delete->fct_stack);
    elf_end(to_delete->elf);
    close(to_delete->fd);
    free(to_delete->name);
    free(to_delete);
}
