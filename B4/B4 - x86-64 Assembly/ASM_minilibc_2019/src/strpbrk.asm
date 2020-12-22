;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strpbrk:function                       ; declare function

SECTION .text

strpbrk:
        push    rbp                     ; saving base pointer to the stack
        mov     rbp, rsp                ; move base pointer to top of the stack
        cmp     rdi, 0                  ; check if first param is null
        jz      strpbrk_end_null        ; if yes return null
        cmp     rsi, 0                  ; check if second param is null
        jz      strpbrk_end_null        ; if yes return null
        xor     rcx, rcx                ; counter to 0
        jmp     strpbrk_loop            ; go to loop find

strpbrk_loop:
        cmp     [rdi], byte 0           ; check it's the end of str1
        jz      strpbrk_end_null        ; if yes, no occurence return null
        mov     r8b, [rdi]              ; mov current char of str1 to r8b
        jmp     strpbrk_cmp             ; go to compare with str2

strpbrk_return_loop:
        inc     rdi                     ; go to next char of str1
        xor     rcx, rcx                ; reset counter
        jmp     strpbrk_loop            ; return to main loop

strpbrk_cmp:
        cmp     [rsi + rcx], byte 0     ; compare if it's the end of occurence
        jz      strpbrk_return_loop     ; if yes, no occurence, return to main loop
        mov     r9b, [rsi + rcx]        ; mov current char of string occurence in r9b
        cmp     r8b, r9b                ; cmp two char
        jz      strpbrk_end             ; if yes, go to end, found !
        inc     rcx                     ; go to next char of string occurence
        jmp     strpbrk_cmp             ; loop

strpbrk_end:
        mov     rax, rdi                ; mov pointer to the occurence in rax
        mov     rsp, rbp                ; restore stack
        pop     rbp                     ; delete elem
        ret                             ; finish

strpbrk_end_null:
        xor     rax, rax                ; rax = 0
        mov     rsp, rbp                ; restore stack
        pop     rbp                     ; delete elem
        ret                             ; finish