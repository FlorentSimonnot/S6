extern printf
extern scanf

section .bss
    globals resb 16

section .data
    format_ent db "%d", 10, 0
    format_sent db "%d\n", 10, 0

section .text

global _start

_print_car:
    mov rax, 1
    push rsi
    mov rdi, 1
    mov rsi, rsp
    mov rdx, 1
    syscall
    pop rsi
    ret

_print_ent:
    mov rdi, format_ent
    mov rax, 0
    call printf WRT ..plt
    ret

_readc:
    mov rax, 0
    mov rdi, 0
    mov rdx, 1
    syscall
    ret

_reade:
    mov rax, 0
    mov rdi, format_sent
    call scanf
    ret

_start:
    call main
    jmp _end

main:
    push rbp
    mov rbp, rsp
    push QWORD 11
    pop rcx
    push QWORD 25
    pop rcx
    push QWORD [globals+8]
    pop rsi
    call _print_ent
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbp
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
