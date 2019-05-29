section .data

section .text                   
        
global   _int_cmp

extern print_registers 

_int_cmp:
        xor eax, eax
        xor ebx, ebx
        mov eax, DWORD[rdi]
        mov ebx, DWORD[rsi]
        sub eax, ebx

        ret

_start : 
    push rbp 
    mov rbp, rsp

    sub rsp, 8
    mov rsp, 0
    mov rdi, rsp 

    sub rsp, 8
    mov rsp, 3
    mov rsi, rsp

    call _int_cmp

    mov rsp, rbp
    pop rbp

    mov rax, 0
    mov rbx, 1
    int 0x80