;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strchr:function                       ; declare function

SECTION .text

strchr:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        cmp     rdi, 0              ; check if the first param is null
        jz      strchr_end_null     ; if yes, go to return null

strchr_loop:
        cmp     [rdi], sil          ; cmp if character is the search character, we have to use sil to compare the first 8 octets
        jz      strchr_end          ; if yes, go to end
        cmp     [rdi], byte 0       ; check if it's the end of the string
        jz      strchr_end_null     ; if yes, not found, return null
        inc     rdi                 ; increment rdi for the next char
        jmp     strchr_loop         ; boucle

strchr_end:
        mov     rax, rdi            ; return pointer on the occurence
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish

strchr_end_null:
        xor     rax, rax            ; rax = 0
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish
