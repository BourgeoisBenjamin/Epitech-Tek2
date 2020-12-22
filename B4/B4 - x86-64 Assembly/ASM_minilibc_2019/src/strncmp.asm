;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strncmp:function                       ; declare function

SECTION .text

strncmp:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        xor     rcx, rcx            ; set RCX to 0
        cmp     rdx, rcx            ; if no character to compare
        jz      strncmp_null        ; return 0
        cmp     rdi, 0              ; test if the first param is null
        jz      strncmp_null        ; if yes return
        cmp     rsi, 0              ; test if the second param is null
        jz      strncmp_null        ; if yes return

strncmp_loop:
        cmp     rdx, rcx            ; check if counter == n
        jz      strncmp_end         ; if yes, go to end
        mov     al, [rdi + rcx]     ; move current character of str1 in al
        mov     ah, [rsi + rcx]     ; move current character of str2 in ah
        cmp     al, byte 0          ; check if end of str1
        jz      strncmp_end         ; if yes go to end
        cmp     ah, byte 0          ; check if end of str2
        jz      strncmp_end         ; if yes go to end
        cmp     al, ah              ; check [str1] == [str2]
        jnz     strncmp_end         ; if no go to end
        inc     rcx                 ; increment for next character
        jmp     strncmp_loop        ; loop

strncmp_end:
        sub     al, ah              ; substraction of the two character
        movsx   rax, al             ; move result in return registry, we can't move directly al in rax, we have to use movsx because al is 8 bit registry
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish

strncmp_null:
        mov     rax, 0              ; if no character to compare, return 0
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish