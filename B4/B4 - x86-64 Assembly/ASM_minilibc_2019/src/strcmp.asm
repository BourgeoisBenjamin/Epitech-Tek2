;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strcmp:function                       ; declare function

SECTION .text

strcmp:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        xor     rcx, rcx            ; set RCX to 0
        cmp     rdi, 0              ; test if the first param is null
        jz      strcmp_end          ; if yes return
        cmp     rsi, 0              ; test if the first param is null
        jz      strcmp_end          ; if yes return

strcmp_loop:
        mov     al, [rdi + rcx]     ; move current character of str1 in al
        mov     ah, [rsi + rcx]     ; move current character of str2 in ah
        cmp     al, byte 0          ; check if end of str1
        jz      strcmp_end          ; if yes go to end
        cmp     ah, byte 0          ; check if end of str2
        jz      strcmp_end          ; if yes go to end
        cmp     al, ah              ; check [str1] == [str2]
        jnz     strcmp_end          ; if no go to end
        inc     rcx                 ; increment for next character
        jmp     strcmp_loop         ; loop

strcmp_end:
        sub     al, ah              ; substraction of the two character
        movsx   rax, al             ; move result in return registry, we can't move directly al in rax, we have to use movsx because al is 8 bit registry
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish