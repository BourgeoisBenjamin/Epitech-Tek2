;
; EPITECH PROJECT - 2020
; benjamin.bourgeois@epitech.eu
;

BITS 64

GLOBAL strcasecmp:function                       ; declare function

SECTION .text

strcasecmp:
        push    rbp                 ; saving base pointer to the stack
        mov     rbp, rsp            ; move base pointer to top of thestack
        xor     rcx, rcx            ; set RCX to 0
        cmp     rdi, 0              ; test if the first param is null
        jz      strcasecmp_end      ; if yes return
        cmp     rsi, 0              ; test if the first param is null
        jz      strcasecmp_end      ; if yes return

strcasecmp_loop:
        mov     al, [rdi + rcx]     ; move current character of str1 in al
        mov     ah, [rsi + rcx]     ; move current character of str2 in ah
        cmp     al, byte 0          ; check if end of str1
        jz      strcasecmp_end      ; if yes go to end
        cmp     ah, byte 0          ; check if end of str2
        jz      strcasecmp_end      ; if yes go to end
        jmp     strcasecmp_lower1   ; go to verification for case

strcasecmp_lower1:
        cmp     al, 'a'             ; check if char1 < a
        jl      strcasecmp_lower2   ; if yes, go to verif for char2
        cmp     al, 'z'             ; check if char2 > z
        jg      strcasecmp_lower2   ; if yes, go to verif for char2
        sub     al, 32              ; if not, char1 is lower, transform to upper
        jmp     strcasecmp_lower2   ; go to verif char char2

strcasecmp_lower2:
        cmp     ah, 'a'             ; check if char1 < a
        jl      strcasecmp_char     ; if yes, go to verif for char2
        cmp     ah, 'z'             ; check if char2 > z
        jg      strcasecmp_char     ; if yes, go to verif for char2
        sub     ah, 32              ; if not, char1 is lower, transform to upper
        jmp     strcasecmp_char     ; go to verif char char2

strcasecmp_char:
        cmp     al, ah              ; check [str1] == [str2]
        jnz     strcasecmp_end      ; if no go to end
        inc     rcx                 ; increment for next character
        jmp     strcasecmp_loop     ; loop

strcasecmp_end:
        sub     al, ah              ; substraction of the two character
        movsx   rax, al             ; move result in return registry, we can't move directly al in rax, we have to use movsx because al is 8 bit registry
        mov     rsp, rbp            ; restore stack
        pop     rbp                 ; delete elem
        ret                         ; finish