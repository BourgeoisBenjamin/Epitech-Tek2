/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"
#include <stdio.h>
#include <sys/ptrace.h>

const info_args_t info_args[] =
{
    {CONST_VOID_E, print_void_e},
    {CONST_CHAR_E, print_char_e},
    {CHAR_E, print_char_e},
    {VOID_E, print_void_e},
    {CHAR_EE, print_char_ee},
    {CONST_CHAR_E_CONST, print_char_ee},
    {INT_E, print_int_e},
    {CONST_INT_E, print_int_e},
    {INT, print_int},
    {PID_T, print_unsigned_int},
    {UID_T, print_unsigned_int},
    {GID_T, print_unsigned_int},
    {UID_T_E, print_unsigned_int_e},
    {GID_T_E, print_unsigned_int_e},
    {MODE_T, print_unsigned_int},
    {UNSIGNED_INT, print_unsigned_int},
    {SIZE_T, print_size_t},
    {SIZE_T_E, print_size_t_e},
    {SSIZE_T, print_ssize_t},
    {STRUCT_STAT_E, print_struct_stat_e},
    {LONG, print_long},
    {UNSIGNED_LONG, print_unsigned_long},
    {OFF_T, print_long},
    {OFF_T_E, print_long_e},
    {CLOCK_T, print_long},
    {TIME_T, print_long},
    {ID_T, print_unsigned_int},
    {KEY_T, print_int},
    {LOFF_T, print_unsigned_long},
    {LOFF_T_E, print_unsigned_long_e},
    {MODE_T, print_unsigned_int},
    {UNSIGNED, print_unsigned_int},
    {UNSIGNED_LONG_E, print_unsigned_long_e},
    {CONST_UNSIGNED_LONG_E, print_unsigned_long_e},
    {QID_T, print_char_e},
    {MQD_T, print_int},
    {UNKNOWN, NULL},
};

sys_type get_arg_type(int syscall_id, int arg_ng)
{
    switch (arg_ng) {
    case 1:
        return (syscalls[syscall_id].p1);
    case 2:
        return (syscalls[syscall_id].p2);
    case 3:
        return (syscalls[syscall_id].p3);
    case 4:
        return (syscalls[syscall_id].p4);
    case 5:
        return (syscalls[syscall_id].p5);
    case 6:
        return (syscalls[syscall_id].p6);
    default:
        return (UNKNOWN);
    }
}

void print_arg_details(strace_info_t *info, const unsigned long long int
registers[], int i, struct user_regs_struct regs)
{
    sys_type type = get_arg_type(regs.orig_rax, i + 1);

    for (size_t a = 0; info_args[a].type != UNKNOWN; a++) {
        if (info_args[a].type == type) {
            info_args[a].fct(info->child_pid, registers[i], regs);
            return;
        }
    }
    if (registers[i] == 0)
        fprintf(stderr, "NULL");
    else
        fprintf(stderr, "0x%llx", registers[i]);
}