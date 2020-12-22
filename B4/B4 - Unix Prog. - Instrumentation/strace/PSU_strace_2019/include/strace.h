/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#ifndef PSU_STRACE_2019_STRACE_H
#define PSU_STRACE_2019_STRACE_H

#include <sched.h>
#include <stdbool.h>
#include "syscall.h"
#include <sys/user.h>

typedef struct strace_info_s
{
    bool flag_s;
    bool flag_p;
    pid_t child_pid;
    int argc;
    char **argv;
    char **envp;
    char **cmd;
} strace_info_t;

typedef struct info_args_s
{
    sys_type type;
    void (*fct)(pid_t, unsigned long, struct user_regs_struct);
} info_args_t;


int strace(int argc, char **argv, char **envp);

/* INIT FUNCTION */
strace_info_t *init_strace(int argc, char **argv, char **envp);

/* PARSING */
void is_help_option(strace_info_t *info, int i);
int is_s_option(strace_info_t *info, int i);
int is_p_option(strace_info_t *info, int i);
void add_cmd_arg(strace_info_t *info, char *cmd);
int parse_arg(strace_info_t *info);

/* ERROR / HELP */
void help(char *exec_name);
int strace_error(strace_info_t *info);

/* FREE */
void free_strace(strace_info_t *info);

/* CMD */
int trace_pid(strace_info_t *info);

/* PROG */
int trace_prog(strace_info_t *info);
char *get_sys_name(unsigned long long int id);

/* CHILD */
int trace_child(strace_info_t *info);

/* PRINT SYSCALL */
void print_syscall(struct user_regs_struct regs, strace_info_t *info);
void print_args(struct user_regs_struct regs, strace_info_t *info);
int get_nb_args(int id);
void print_arg_details(strace_info_t *info, const unsigned long long int
registers[], int i, struct user_regs_struct regs);
sys_type get_arg_type(int syscall_id, int arg_ng);

/* FUNCTION FOR ARGS */
void print_char_e(pid_t child, unsigned long addr, struct user_regs_struct
regs);
void print_void_e(pid_t child, unsigned long addr, struct user_regs_struct
regs);
void print_char_ee(pid_t child, unsigned long addr, struct user_regs_struct
regs);
void print_int(pid_t child, unsigned long addr, struct user_regs_struct regs);
void print_unsigned_int(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_size_t(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_ssize_t(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_int_e(pid_t child, unsigned long addr, struct user_regs_struct regs);
void print_struct_stat_e(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_unsigned_long(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_long(pid_t child, unsigned long addr, struct user_regs_struct regs);
void print_unsigned_int_e(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_unsigned_long_e(pid_t child, unsigned long addr, struct
user_regs_struct regs);
void print_size_t_e(pid_t child, unsigned long addr, struct user_regs_struct
regs);
void print_long_e(pid_t child, unsigned long addr, struct user_regs_struct
regs);

#endif //PSU_STRACE_2019_STRACE_H
