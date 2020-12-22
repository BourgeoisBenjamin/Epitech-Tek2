BITS 64

global _start
extern my_strlen, printf

SECTION .text

_start:

        mov rdi, str    ; rdi is the string we want to
                            ; get the length of
        call my_strlen       ; get the length!

        mov rdx, rax      ; rdx now holds the string length

        mov rdi, msg
        mov rsi, rax
        call printf

        mov rax, 60
        xor rdi, rdi
        syscall

SECTION .rodata
msg:    DB "%i", 10
str:    DB "Salut"