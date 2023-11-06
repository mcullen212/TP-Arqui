GLOBAL invalidOp

section .text
invalidOp:
    jmp inval
    ret

section .data 
    inval equ 42849