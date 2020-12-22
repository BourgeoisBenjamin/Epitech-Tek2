;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL memmove:function                       ; declare function

SECTION .text

memmove:
        push    rbp                         ; saving base pointer to the stack
        mov     rbp, rsp                    ; move base pointer to top of thestack
        mov     rax, rdi
        xor     rcx, rcx
        cmp     rdx, 0                      ; check if we do not have bytes to copy
        jz      memmove_end                 ; if yes, go to end
        cmp     rsi, rdi                    ; check if rsi < rdi
        jl      memmove_overlap2            ; if so overlap on right we can do a memcpy from the end
        jmp     memmove_overlap1            ; if no overlap on left

memmove_overlap1:
        cmp     rdx, rcx                    ; test if counter == size
        jz      memmove_end                 ; if yes return
        mov     r8b, byte [rsi + rcx]       ; get char at rsi + rcx into r8b
        mov     byte [rdi + rcx], r8b       ; put r8b char into rdi + rcx
        inc     rcx                         ; increment rcx counter
        jmp     memmove_overlap1            ; loop

memmove_overlap2:
        dec     rdx                         ; decremente counter
        mov     r8b, byte [rsi + rdx]       ; from the last, copy char in 8 bit register
        mov     byte [rdi + rdx], r8b       ; move the char in dest
        cmp     rdx, 0                      ; compare if it's the end of the copy
        jz      memmove_end                 ; if yes go to end
        jmp     memmove_overlap2            ; if no loop

memmove_end:
        mov rsp, rbp                        ; restore stack
        pop rbp                             ; delete elem
        ret                                 ; return