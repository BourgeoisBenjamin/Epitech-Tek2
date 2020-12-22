;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL memcpy:function                       ; declare function

SECTION .text

memcpy:
        push    rbp                   ; saving base pointer to the stack
        mov     rbp, rsp              ; move base pointer to top of the stack
        xor     rcx, rcx              ; set RCX to 0
        cmp     rdi, 0                ; test if the first param is null
        jz      memcpy_end            ; if yes return

memcpy_loop:
        cmp     rdx, rcx              ; test if counter == size
        jz      memcpy_end            ; if yes return
        mov     al, [rsi + rcx]       ; get char at rsi + rcx into al
        mov     [rdi + rcx], al       ; put al char into rdi + rcx
        inc     rcx                   ; increment rcx counter
        jmp     memcpy_loop           ; loop

memcpy_end:
        mov     rax, rdi              ; return pointer on the string
        mov     rsp, rbp              ; restore stack
        pop     rbp                   ; delete elem
        ret                           ; finish