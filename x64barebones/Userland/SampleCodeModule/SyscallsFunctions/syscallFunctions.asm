GLOBAL call_read
GLOBAL call_write
GLOBAL call_print_char

call_read:
    push rbp
    mov rbp, rsp

    mov rax, 0 ; read
    int 80h
    
    mov rsp, rbp
    pop rbp
    ret

call_write:
    push rbp
    mov rbp, rsp

    mov rax, 1 ; write
    int 80h
    
    mov rsp, rbp
    pop rbp
    ret

call_print_char:
    push rbp
    mov rbp, rsp

    mov rax, 4 ; write
    mov rbx, 1 ; stdout
    mov rcx, [rbp+16]
    mov rdx, 1 ; length
    int 80h
    
    mov rsp, rbp
    pop rbp
    ret
