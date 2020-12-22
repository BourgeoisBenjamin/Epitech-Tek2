/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** functions that display function calls
*/

#include "ftrace.h"

void display_call(struct user_regs_struct *regs, ftrace_info_t *info)
{
    char *name = get_name_from_info(info, regs->rip);
    char *lib;
    long long unsigned lib_addr;

    if (!name || strlen(name) == 0) {
        lib = get_lib_path(info, regs->rip, &lib_addr);
        if (!lib)
            name = addr_not_found(info->name, regs->rip);
        else {
            name = get_name_symbol(lib, regs->rip - lib_addr);
        }
    }
    if (!name || strlen(name) == 0)
        name = addr_not_found(info->name, regs->rip);
    if (!name) {
        dprintf(2, "Entering function\n");
    } else {
        dprintf(2, "Entering function %s at 0x%llx\n", name, regs->rip);
    }
    stack_push(&info->fct_stack, name);
}

void display_ret(ftrace_info_t *info)
{
    char *fct_name = stack_top(info->fct_stack);

    if (fct_name)
        dprintf(2, "Leaving function %s\n", fct_name);
    stack_pop(&info->fct_stack);
}
