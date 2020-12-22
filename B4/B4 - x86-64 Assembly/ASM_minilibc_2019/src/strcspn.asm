;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strcspn:function                       ; declare function

SECTION .text

strcspn:
        push    rbp                     ; saving base pointer to the stack
        mov     rbp, rsp                ; move base pointer to top of the stack
        cmp     rdi, 0                  ; check if first param is null
        jz      strcspn_end             ; if yes return null
        cmp     rsi, 0                  ; check if second param is null
        jz      strcspn_end             ; if yes return null
        xor     rcx, rcx                ; counter to 0
        xor     rax, rax                ; set rax to 0
        jmp     strcspn_loop            ; go to loop find

strcspn_loop:
        cmp     [rdi], byte 0           ; check it's the end of str1
        jz      strcspn_end             ; if yes, no occurence return null
        mov     r8b, [rdi]              ; mov current char of str1 to r8b
        jmp     strcspn_cmp             ; go to compare with str2

strcspn_return_loop:
        inc     rdi                     ; go to next char of str1
        xor     rcx, rcx                ; reset counter
        inc     rax                     ; increment rax
        jmp     strcspn_loop            ; return to main loop

strcspn_cmp:
        cmp     [rsi + rcx], byte 0     ; compare if it's the end of occurence
        jz      strcspn_return_loop     ; if yes, no occurence, return to main loop
        mov     r9b, [rsi + rcx]        ; mov current char of string occurence in r9b
        cmp     r8b, r9b                ; cmp two char
        jz      strcspn_end             ; if yes, go to end, found !
        inc     rcx                     ; go to next char of string occurence
        jmp     strcspn_cmp             ; loop

strcspn_end:
        mov     rsp, rbp                ; restore stack
        pop     rbp                     ; delete elem
        ret                             ; finish