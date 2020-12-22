;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL rindex:function              ; declare function

SECTION .text

rindex:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        xor     rcx, rcx            ; set RCX to 0
        xor     rax, rax            ; set return to null by default
        cmp     rdi, 0              ; test if the first param is null
        jz      rindex_null         ; if yes return

rindex_endstr:
        cmp     [rdi], byte 0       ; test if it's the end of the string
        jz      rindex_find         ; if yes, go to find character
        inc     rdi                 ; go to next character
        inc     rcx                 ; inc counter for size
        jmp     rindex_endstr       ; loop

rindex_find:
        cmp     [rdi], sil          ; test if it's the last occurence
        jz      rindex_end          ; if yes, go to end
        cmp     rcx, 0              ; test if there is no occurence
        jz      rindex_null         ; if yes go to end null
        dec     rdi                 ; go to previous character
        dec     rcx                 ; dec size for check no occurence
        jmp     rindex_find         ; loop

rindex_end:
        mov     rax, rdi            ; move last occurence in return registry
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish

rindex_null:
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish