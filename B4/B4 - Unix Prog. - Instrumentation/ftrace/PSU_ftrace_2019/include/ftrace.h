/*
** EPITECH PROJECT, 2020
** ftrace
** File description:
** header file
*/

#ifndef FTRACE_H_
#define FTRACE_H_

#include <sys/user.h>
#include <sys/ptrace.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <gelf.h>

#include "linked_list/stack.h"

typedef struct {
    mystack_t fct_stack;
    Elf *elf;
    Elf_Scn *elf_scn;
    GElf_Shdr elf_shdr;
    int fd;
    char *name;
    pid_t child_pid;
} ftrace_info_t;

void display_usage(void);
int my_ftrace(char **av);
void display_syscall(struct user_regs_struct *regs);
void strace_sig_handler(int sig);
pid_t wrap_traced_pid(bool stock, pid_t pid);
char *get_signal_name(int code);
int trace_signal(int pid);
char *get_lib_path(ftrace_info_t *info, unsigned long long addr, \
unsigned long long *lib_addr);

int read_from_pid(pid_t pid, void *addr, size_t size, void *to_fill);

char *get_name_symbol(char *path, long long unsigned addr);
char *addr_not_found(char *name, long long unsigned addr);
bool is_between_addr(char *s1, char *s2, unsigned long long addr, \
unsigned long long *lib_addr);

struct arg_type_displayer {
    int arg_type;
    void (*display_arg)(unsigned long long arg, pid_t child);
};

bool is_syscall(const struct user_regs_struct *regs);
bool is_function_call(unsigned long long data);
bool is_ret(unsigned long long data);

void find_symbol_table(Elf *elf, GElf_Shdr *shdr, Elf_Scn **scn);

int find_and_open_file(const char *name);

ftrace_info_t *ftrace_info_init(const char *filepath);
void ftrace_info_delete(ftrace_info_t *to_delete);
char *get_name_from_info(ftrace_info_t *info, unsigned long long address);

char **split_str(const char *str, const char *separator);

void display_call(struct user_regs_struct *regs, ftrace_info_t *info);
void display_ret(ftrace_info_t *info);

char **my_strtok(char *str, char sep);
int get_size_array(char **array);
char **free_array(char **array);

enum arg_types {
    NO_ARG,
    STRING,
    INT,
    UINT,
    LONG,
    ULONG,
    PTR,
    STRUCT_STAT,
    STRUCT_POLL_FD,
    STRUCT_SIGACTION,
    STRUCT_IOVEC,
    STRUCT_TIMEVAL,
    STRUCT_SHMID_DS,
    STRUCT_TIMESPEC,
    STRUCT_ITIMERVAL,
    STRUCT_SOCKADDR,
    STRUCT_MSGHDR,
    STRUCT_SOKADDR,
    STRUCT_RUSAGE,
    STRUCT_OLD_UTSNAME,
    STRUCT_SEMBUF,
    STRUCT_MSGBUF,
    STRUCT_MSQID_DS,
    STRUCT_LINUX_DIRENT,
    STRUCT_TIMEZONE,
    STRUCT_RLIMIT,
    STRUCT_SYSINFO,
    STRUCT_UTIMBUF,
    STRUCT_USTAT,
    STRUCT_STATFS,
    STRUCT_SCHED_PARAM,
    STRUCT___SYSCTL_ARGS,
    STRUCT_TASK_STRUCT,
    STRUCT_TIMEX,
    STRUCT_PT_REGS,
    STRUCT_IO_EVENT,
    STRUCT_IOCB,
    STRUCT_LINUX_DIRENT64,
    STRUCT_SIGEVENT,
    STRUCT_ITIMERSPEC,
    STRUCT_EPOLL_EVENT,
    STRUCT_MQ_ATTR,
    STRUCT_KEXEC_SEGMENT,
    STRUCT_SIGINFO,
    STRUCT_POLLFD,
    STRUCT_ROBUST_LIST_HEAD,
    STRUCT_PERF_EVENT_ATTR,
    STRUCT_RLIMIT64,
    STRUCT_FILE_HANDLE,
    STRUCT_MMSGHDR,
    STRUCT_GETCPU_CACHE,
    STRUCT_IOVCC,
    STRUCT_SCHED_ATTR,
    STRUCT_KERNEL_SYM,
    STRUCT_STRBUF,
    STRUCT_CPU_SET,
    STRUCT_SIGSET,
    FDSET,
    STRUCT_TMS,
    CAP_USER_DATA,
    CAP_USER_HEAD,
    STRUCT_STACK,
    STRUCT_USER_DESC,
    STRUCT_STATX
};

typedef struct {
    int code;
    char *name;
    enum arg_types args[6];
} syscalls_t;

typedef struct {
    int code;
    char *name;
} signals_t;

extern const syscalls_t syscalls[];
extern const signals_t signals[];

#endif /* FTRACE_H_ */
