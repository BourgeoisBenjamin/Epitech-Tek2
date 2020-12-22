SECTION .text
    global main

main:
    MOV RAX, 1
    MOV RBX, 20
    int 80h
