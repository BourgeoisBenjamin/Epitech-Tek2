#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/time.h>
#include <sys/resource.h>

int waitchild(pid_t pid)
{
    int status;
    struct rusage resource;
    wait4(pid, &status, 0, &resource);

    if (WIFSTOPPED(status)) {
        return 0;
    } else if (WIFEXITED(status)) {
        return 1;
    } else {
        printf("%d raised an unexpected status %d", pid, status);
        return 1;
    }
}

void trace(pid_t child)
{
    int status = 0;
    waitpid(child, &status, 0);
    do {
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status)) {
            printf("syscall ... ");
            struct user_regs_struct regs;
            ptrace(PTRACE_GETREGS, child, 0, &regs);
        }
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status))
            printf("ret\n");
    } while (WIFSTOPPED(status));
}

int main(int argc, char **argv)
{
    pid_t child = fork();

    if (child == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execve(argv[1], argv, NULL);
    } else {
        trace(child);
        printf("The child tracing is now done.\n");
    }
    return 0;
}