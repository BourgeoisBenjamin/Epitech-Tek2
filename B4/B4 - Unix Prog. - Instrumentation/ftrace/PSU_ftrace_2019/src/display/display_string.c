/*
** EPITECH PROJECT, 2020
** strace
** File description:
** Display string
*/

#include "ftrace.h"

static int display_peektext(unsigned long long text)
{
    char c = 0;

    for (int i = 0; i < 8; i++) {
        c = text & 0xff;
        text >>= 8;
        if (!c)
            return (0);
        if (c >= ' ' && c <= '~') {
            dprintf(2, "%c", c);
        } else {
            dprintf(2, "/%d", c);
        }
    }
    return (1);
}

void display_string(unsigned long long arg, pid_t child)
{
    unsigned long text = 0;
    int ret = 1;

    dprintf(2, "\"");
    if (!arg) {
        dprintf(2, "\"");
        return;
    }
    for (int i = 0; i < 4 && ret; i++) {
        text = ptrace(PTRACE_PEEKDATA, child, arg + i * 8, 0);
        if ((long)text == -1) {
            dprintf(2, "\"");
            return;
        }
        ret = display_peektext(text);
    }
    if (ret) {
        text = ptrace(PTRACE_PEEKDATA, child, arg + 4 * 8, 0);
        dprintf(2, "\"%s", ((long){text} == -1 && text & 0xff) ? "" : "...");
    } else
        dprintf(2, "\"");
}
