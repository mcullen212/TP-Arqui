GLOBAL saveReference
GLOBAL jumpToReference

saveReference:      ; Address of first field of the struct in rdi
    mov rdx, rdi    ; First adress of the struct
    pop rsi         ; Save rip

    mov [rdi], r15  ; Save r15
    add rdi, 8

    mov [rdi], r14  ; Save r14
    add rdi, 8

    mov [rdi], r13  ; Save r13
    add rdi, 8

    mov [rdi], r12  ; Save r12
    add rdi, 8

    mov [rdi], r11  ; Save r11
    add rdi, 8

    mov [rdi], rcx  ; Save rcx
    add rdi, 8

    mov [rdi], rbx  ; Save rbx
    add rdi, 8

    pushf
    pop rax         ; Save oin rax, rflags
    mov [rdi], rax  ; Save rflags
    add rdi, 8

    mov [rdi], rsp  ; Save rsp
    add rdi, 8

    mov [rdi], rsi  ; Save rip

    mov rdi, rdx    ; Reset struct adress
    push rsi        ; Push ret adress
    ret

jumpToReference:
    mov r15, [rdi]
    add rdi, 8

    mov r14, [rdi]
    add rdi, 8

    mov r13, [rdi]
    add rdi, 8

    mov r12, [rdi]
    add rdi, 8

    mov r11, [rdi]
    add rdi, 8

    mov rcx, [rdi]
    add rdi, 8

    mov rbx, [rdi]
    add rdi, 8

    push qword [rdi]
    popf
    add rdi, 8

    mov rsp, [rdi]
    add rdi, 8

    mov rsi, [rdi]  ; Save rip on rsi
    jmp rsi         ; jmp to the reference rip




