;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strlen:function                       ; declare function

SECTION .text

strlen:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        xor     rax, rax            ; reset rax to 0

strlen_loop:
        cmp     [rdi], byte 0       ; cmp if rdi is null byte
        jz      strlen_end          ; if yes, go to end
        inc     rax                 ; else increment rax
        inc     rdi                 ; increment rdi for the next char
        jmp     strlen_loop         ; boucle

strlen_end:
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish