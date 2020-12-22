/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "strace.h"

static void print_struct_stat_e_mode(pid_t child, unsigned long addr, struct
user_regs_struct regs)
{
    (void)regs;
    fprintf(stderr, "st_mode=");
    long st_mode = ptrace(PTRACE_PEEKDATA, child, addr + 3 * sizeof(long),
    NULL);
    switch (st_mode & S_IFMT) {
    case S_IFBLK: fprintf(stderr, "S_IFBLK"); break;
    case S_IFCHR: fprintf(stderr, "S_IFCHR"); break;
    case S_IFDIR: fprintf(stderr, "S_IFDIR"); break;
    case S_IFIFO: fprintf(stderr, "S_IFIFO"); break;
    case S_IFLNK: fprintf(stderr, "S_IFLNK"); break;
    case S_IFREG: fprintf(stderr, "S_IFREG"); break;
    case S_IFSOCK: fprintf(stderr, "S_IFSOCK"); break;
    default: fprintf(stderr, "?"); break;
    }
    fprintf(stderr, "|");
    fprintf(stderr, (S_ISDIR(st_mode)) ? "1" : "0");
    fprintf(stderr, "%lo", (st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)));
    fprintf(stderr, ", ");
}

static void print_struct_stat_e_size(pid_t child, unsigned long addr, struct
user_regs_struct regs)
{
    (void)regs;
    off_t st_size = ptrace(PTRACE_PEEKDATA, child, addr + 6 * sizeof(long),
    NULL);
    fprintf(stderr, "st_size=%li, ...", st_size);
}

void print_struct_stat_e(pid_t child, unsigned long addr, struct
user_regs_struct regs)
{
    if (addr == 0) {
        fprintf(stderr, "NULL");
        return;
    }
    fprintf(stderr, "{");
    print_struct_stat_e_mode(child, addr, regs);
    print_struct_stat_e_size(child, addr, regs);
    fprintf(stderr, "}");
}