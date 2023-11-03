GLOBAL call_read
GLOBAL call_write
GLOBAL call_draw_char
GLOBAL call_delete_char
GLOBAL call_get_time
GLOBAL call_set_theme
GLOBAL call_c_get_x
GLOBAL call_c_get_y
GLOBAL call_c_get_scale
GLOBAL call_c_set_scale
GLOBAL call_c_move
GLOBAL call_c_init
GLOBAL call_set_colors
GLOBAL call_get_registers
GLOBAL call_draw_square

section .text

%macro pushAll 0
	push rbx
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro popAll 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
%endmacro

call_read:
    push rbp
    mov rbp, rsp
    pushAll

    mov rax, 0 ; Read
    int 80h

    popAll
    mov rsp, rbp
    pop rbp
    ret

call_write:
    push rbp
    mov rbp, rsp
    pushAll

    mov rax, 1 ; Write
    int 80h

    popAll
    mov rsp, rbp
    pop rbp
    ret

call_draw_char:
    push rbp
    mov rbp, rsp
    pushAll

    mov dword rax, 2
    int 80h

    popAll
    mov rsp, rbp
    pop rbp
    ret

call_delete_char:
    push rbp
    mov rbp, rsp
    pushAll

    mov rax, 3  ; Delete char
    int 80h

    popAll
    mov rsp, rbp
    pop rbp
    ret

call_get_time:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 4
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_pool_char:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 4
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_set_theme:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 5
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_set_exception_handler:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 6
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_c_get_x:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 7
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

    call_c_get_y:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 8
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

    call_c_get_scale:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 9
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_c_set_scale:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 10
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_c_move:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 11
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_c_init:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 12
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_set_colors:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 13
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_get_registers:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 14
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret

call_draw_square:
    push rbp
    mov rbp, rsp

    pushAll

    mov rax, 15
    int 80h

    popAll

    mov rsp, rbp
    pop rbp
    ret