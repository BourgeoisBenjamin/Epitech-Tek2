;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL memset:function                       ; declare function

SECTION .text

memset:
        push    rbp                         ; saving base pointer to the stack
        mov     rbp, rsp                    ; move base pointer to top of thestack
        xor     rcx, rcx                    ; set RCX to 0
        cmp     rdi, 0                      ; test if the first param is null
        jz      memset_end                  ; if yes return

memset_loop:
        cmp     rdx, rcx                    ; test if counter == size
        jz      memset_end                  ; if yes return
        mov     [rdi + rcx], sil            ; set value of rdi + rcx to the second param
        inc     rcx                         ; increment rcx counter
        jmp     memset_loop                 ; loop

memset_end:
        mov     rax, rdi                    ; return pointer on the string
        mov     rsp, rbp                    ; restore stack
        pop     rbp                         ; delete elem
        ret                                 ; finish