section .data

section .text                   
        
global   _int_cmp, _swap

extern print_registers 

_int_cmp:
        xor rax, rax
        xor rbx, rbx
        push rsi
        push rdi 
        pop rax 
        pop rbx 
        sub rax, rbx

        ret

_start : 
    push rbp 
    mov rbp, rsp

    mov rax, 8
    mov rbx, 3

    sub rsp, 8
    push rax
    mov rdi, rsp 

    sub rsp, 8
    push rbx
    mov rsi, rsp

    call _int_cmp

    call print_registers

    mov rsp, rbp
    pop rbp

    mov rax, 0
    mov rbx, 1
    int 0x80