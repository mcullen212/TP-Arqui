
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq80Handler

GLOBAL _exception0Handler
GLOBAL _exception6Handler

EXTERN irqDispatcher
EXTERN exceptionDispatcher
EXTERN syscallsDispatcher

EXTERN updateRegs

%macro pushState 0
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
%endmacro

%macro irqHandlerMaster 1
    pushState

    mov rdi, %1
    call irqDispatcher

    ; Se le avisa al PIC que se finalizo la atencion a la interrupcion.
    mov al, 20h
    out 20h, al

    popState
    iretq
%endmacro

%macro exceptionHandler 1
	pushState

	mov rdi, %1  ; Pasaje de parametro
	call exceptionDispatcher

	popState
	iretq
%endmacro

_hlt:
	sti
	hlt
	ret

_cli:
    cli
    ret

_sti:
    sti
    ret

picMasterMask:
    push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
    push rbp
    mov rbp, rsp
    mov ax, di
    out	0A1h,al
    pop rbp
    retn

; Timer Tick
_irq00Handler:
    irqHandlerMaster 0

; Keyboard
_irq01Handler:
    
    push rbp
    push rax
    push rbx
    push rcx
    push rdx
    push rdi
    push rsi 
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    mov rdi, rsp
    call updateRegs

    add rsp, 8 * 15

    irqHandlerMaster 1

; Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

; Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3

; Serial Port 1 and 3
_irq04Handler:
	irqHandlerMaster 4

; USB
_irq05Handler:
	irqHandlerMaster 5

_irq80Handler:
    push rbp
    mov rbp, rsp
    pushState

    ;parameters for systemcalls
    push r9
    push r8
    push rcx
    push rdx
    push rsi
    push rdi

    mov rdi, rax
    mov rsi, rsp   ; stack pointer is pointing towards first element in the stack
    call syscallsDispatcher

    add rsp, 8*6    ; Restablezco el stack

    popState
    mov rsp, rbp
    pop rbp
    iretq

; Exceptions

;Zero Division Exception
_exception0Handler:
	exceptionHandler 0

_exception6Handler:
    exceptionHandler 6

haltcpu:
	cli
	hlt
	ret

SECTION .bss
	aux resq 1

