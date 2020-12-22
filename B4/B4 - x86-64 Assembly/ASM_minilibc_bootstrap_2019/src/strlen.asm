BITS 64

SECTION .text
GLOBAL my_strlen

my_strlen:
        push  rcx            ; save and clear out counter
        xor   rcx, rcx

_strlen_loop:
        cmp   [rdi], byte 0  ; null byte yet?
        jz    _strlen_null   ; yes, get out
        inc   rcx            ; char is ok, count it
        inc   rdi            ; move to next char
        jmp   _strlen_loop   ; process again

_strlen_null:
        mov   rax, rcx       ; rcx = the length (put in rax)
        pop   rcx            ; restore rcx
        ret                  ; get out