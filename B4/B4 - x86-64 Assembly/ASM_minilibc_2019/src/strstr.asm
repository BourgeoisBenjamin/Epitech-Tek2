;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strstr:function                       ; declare function

SECTION .text

strstr:
        push    rbp                     ; saving base pointer to the stack
        mov     rbp, rsp                ; move base pointer to top of the stack
        cmp     rdi, 0                  ; check if first param is null
        jz      strstr_end_null         ; if yes return null
        cmp     byte [rsi], 0                  ; check if second param is null
        jz      strstr_end         ; if yes return null
        xor     rcx, rcx                ; counter to 0
        jmp     strstr_loop             ; go to loop find

strstr_loop:
        cmp     [rdi], byte 0           ; check if it's null
        jz      strstr_end_null         ; if yes, no iteration, return null
        mov     r8b, [rsi]              ; mov current char in r8b
        mov     r9b, [rdi]              ; mov current char in r9b
        cmp     r9b, r8b                ; cmp char of str1 and str2
        jz      strstr_pfind            ; if yes, it's perhaps the beginning of the occurence
        inc     rdi                     ; inc for next char in str1
        jmp     strstr_loop             ; loop

strstr_return_loop:
        add     rdi, rcx                ; it's not an occurence, increment str1 of the length of no occurence
        xor     rcx, rcx                ; reset counter
        jmp     strstr_loop             ; return to main loop

strstr_pfind:
        cmp     [rsi + rcx], byte 0     ; cmp if it's the end of str2
        jz      strstr_end              ; if yes, found ! go to end
        mov     r9b, [rdi + rcx]        ; mov char of str2 in r9b
        mov     r8b, [rsi + rcx]        ; mov char of str1 in r8b
        cmp     r8b, r9b                ; cmp char of str1 and char of str2
        jnz     strstr_return_loop      ; if no, return to main loop
        inc     rcx                     ; inc counter
        jmp     strstr_pfind            ; loop

strstr_end:
        mov     rax, rdi                ; mov pointer to the occurence in rax
        mov     rsp, rbp                ; restore stack
        pop     rbp                     ; delete elem
        ret                             ; finish

strstr_end_null:
        xor     rax, rax                ; rax = 0
        mov     rsp, rbp                ; restore stack
        pop     rbp                     ; delete elem
        ret                             ; finish