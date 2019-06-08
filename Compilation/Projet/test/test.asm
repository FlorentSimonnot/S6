extern printf

extern scanf

   __size___tab__ dq 8
    format_ent db "%d", 10, 0
    format_long db "%ld", 10, 0
    format_sent db "%d\n", 10, 0

section .text

global _start

_start : 
    call main 
    jmp end

main : 
    push rbp
    mov rbp, rsp
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0

fin_main:
    pop rbx
    pop rbx
    pop rbx
    pop rbx
    pop rbx
    pop rbp
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
