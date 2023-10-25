GLOBAL call_read
GLOBAL call_write
GLOBAL call_draw_char
GLOBAL call_delete_char

call_read:
    push rbp
    mov rbp, rsp

    mov rax, 0 ; Read
    int 80h

    mov rsp, rbp
    pop rbp
    ret

call_write:
    push rbp
    mov rbp, rsp

    mov rax, 1 ; Write
    int 80h

    mov rsp, rbp
    pop rbp
    ret

call_draw_char:
    push rbp
    mov rbp, rsp

    mov rax, 2  ; Draw char
    int 80h

    mov rsp, rbp
    pop rbp
    ret

call_delete_char:
    push rbp
    mov rbp, rsp

    mov rax, 3  ; Delete char
    int 80h

    mov rsp, rbp
    pop rbp
    ret
