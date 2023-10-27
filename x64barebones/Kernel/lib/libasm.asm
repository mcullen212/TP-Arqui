GLOBAL cpuVendor
GLOBAL getRTCHour
GLOBAL poolKey
GLOBAL getKeyNumber
GLOBAL realTimeClock


section .text

cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

getRTCHour:
    push rbp
    mov rbp, rsp

    ;cli
    mov al, 4       ; Hour register
    out 70h, al
    in al, 71h
    ;sti

    mov rsp, rbp
    pop rbp
    ret

poolKey:
    push rbp
    mov rbp, rsp

.loop:
    in al, 64h ; Ciclo hasta que el buffer de teclado reciba un imput.
    test al, 1
    jz .loop

    in al, 60h ; Cuando hay un imput, lo retorno en AL

    mov rsp, rbp
    pop rbp
    ret

getKeyNumber:
    push rbp
    mov rbp, rsp

    in al, 60h

    mov rsp, rbp
    pop rbp
    ret

realTimeClock:
    push rbp
    mov rbp, rsp 


    cli ; cancel intruption
    mov al, dil ; mueve valor 0 a al registro
    ; "dame la hora" => 4
    ; rdi es el primer registros que recibe dato en 64 bits 

    ; in es un read data port y out es un write data port
    out 70h, al ; mueve el valor de al al puerto 70h
    in al, 71h ; mueve el valor del puerto 71h al registro ax
    sti ; cuando esta leyendo el reloj no puedas interumpirlo

    mov rsp, rbp
    pop rbp
    ret
