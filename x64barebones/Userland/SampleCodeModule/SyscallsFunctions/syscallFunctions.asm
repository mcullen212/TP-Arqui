GLOBAL call_read
GLOBAL call_write
GLOBAL call_draw_char
GLOBAL call_delete_char
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
    pushState

    mov dword rax, 2
    int 80h

    popState
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
