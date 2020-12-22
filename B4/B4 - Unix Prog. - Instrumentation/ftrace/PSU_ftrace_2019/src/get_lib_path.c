/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** TODO: add description
*/

#include <fcntl.h>
#include <zconf.h>
#include <stdio.h>
#include "ftrace.h"

void get_lib_offset(char **tab, unsigned long long *addr)
{
    if (get_size_array(tab) < 3)
        return;
    unsigned long long offset = strtol(tab[2], NULL, 16);
    *addr -= offset;
}

int is_good_address(char *addr_line, unsigned long long addr, \
unsigned long long *lib_addr)
{
    if (strstr(addr_line, "-") == NULL)
        return (0);
    char **tab = my_strtok(addr_line, '-');
    if (!tab) return (0);
    if (get_size_array(tab) < 2) {
        free_array(tab);
        return (0);
    }
    if (is_between_addr(tab[0], tab[1], addr, lib_addr) == true) {
        free_array(tab);
        return (1);
    }
    free_array(tab);
    return (0);
}

char *find_lib_path(char *line, unsigned long long addr, \
unsigned long long *lib_addr)
{
    char **tab = NULL;
    char *path = NULL;

    if (strstr(line, "/") == NULL) return (NULL);
    if ((tab = my_strtok(line, ' ')) == NULL) return (NULL);
    if (get_size_array(tab) < 2) {
        free_array(tab);
        return (NULL);
    }
    if (is_good_address(tab[0], addr, lib_addr)) {
        path = calloc(strlen(tab[get_size_array(tab) - 1]) + 1, sizeof(char));
        strcpy(path, tab[get_size_array(tab) - 1]);
        get_lib_offset(tab, lib_addr);
        free_array(tab);
        return (path);
    }
    free_array(tab);
    return (NULL);
}

static FILE *get_folder_lib(pid_t child_pid)
{
    FILE *fd = NULL;
    char *path = calloc(PATH_MAX, sizeof(char));

    if (!path) return (NULL);
    sprintf(path, "/proc/%d/maps", child_pid);

    if ((fd = fopen(path, "r")) == NULL) {
        free(path);
        return (NULL);
    }

    return (fd);
}

char *get_lib_path(ftrace_info_t *info, unsigned long long addr, \
unsigned long long *lib_addr)
{
    char *line = NULL;
    size_t len = 0;
    FILE *fd = get_folder_lib(info->child_pid);
    char *lib_path = NULL;
    if (fd == NULL) return (NULL);

    while (getline(&line, &len, fd) != -1) {
        if ((lib_path = find_lib_path(line, addr, lib_addr)) != NULL)
            break;
    }
    fclose(fd);
    return (lib_path);
}