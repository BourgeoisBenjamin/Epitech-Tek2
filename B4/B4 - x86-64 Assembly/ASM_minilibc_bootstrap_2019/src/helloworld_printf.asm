BITS 64

extern printf
global _start

SECTION .text

_start:
    mov rdi, msg
    call printf

    mov rax, 60
    xor rdi, rdi
    syscall

SECTION .rodata

msg:    DB "Salut", 10