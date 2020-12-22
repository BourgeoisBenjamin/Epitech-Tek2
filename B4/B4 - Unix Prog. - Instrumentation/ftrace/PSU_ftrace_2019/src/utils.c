/*
** EPITECH PROJECT, 2020
** ftrace
** File description:
** utils for project ftrace
*/

#include "ftrace.h"

bool is_syscall(const struct user_regs_struct *regs)
{
    return (regs->orig_rax != (unsigned long)-1);
}

bool is_function_call(unsigned long long data)
{
    unsigned char opcode = data & 0xff;
    unsigned long long opcode_field = (data & 0700000) >> (5 * 3);

    if (opcode == 0xe8 || opcode == 0x9a)
        return (true);
    if (opcode == 0xff && (opcode_field == 3 || opcode_field == 2))
        return (true);
    return (false);
}

bool is_ret(unsigned long long data)
{
    unsigned char opcode = data & 0xff;

    return (opcode == 0xc3 || opcode == 0xcb);
}
