GLOBAL call_read
GLOBAL call_write
GLOBAL call_draw_char
GLOBAL call_delete_char
section .text

%macro pushCalleeState 0
	push rbx
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro popCalleeState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
%endmacro

call_read:
    push rbp
    mov rbp, rsp
    pushCalleeState

    mov rax, 0 ; Read
    int 80h

    popCalleeState
    mov rsp, rbp
    pop rbp
    ret

call_write:
    push rbp
    mov rbp, rsp
    pushCalleeState

    mov rax, 1 ; Write
    int 80h

    popCalleeState
    mov rsp, rbp
    pop rbp
    ret

call_draw_char:
    push rbp
    mov rbp, rsp
    pushCalleeState

    mov rax, 2  ; Draw char
    int 80h

    popCalleeState
    mov rsp, rbp
    pop rbp
    ret

call_delete_char:
    push rbp
    mov rbp, rsp
    pushCalleeState

    mov rax, 3  ; Delete char
    int 80h

    popCalleeState
    mov rsp, rbp
    pop rbp
    ret
