extern printf

extern scanf

section .data
    format_ent db "%d", 10, 0
    format_long db "%d", 10, 0
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

_print_long:
    mov rdi, format_long
    mov rax, 0
    call printf WRT ..plt
    ret

_readc:
    mov rax, 0
    mov rdi, 0
    mov rdx, 1
    call scanf
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
     push QWORD 0
    push QWORD 1
    pop rax
    cmp rax,0
    je go_end0
    push QWORD 3
    pop rcx
    mov rax,rcx
go_end0:
    push rax
    pop QWORD [rbp-8]
    push QWORD [rbp-8]
    pop rcx
    push QWORD [rbp-8]
    push QWORD 0
    pop rcx
    pop rax
    cmp rax,rcx
    mov rax,0
    je cond_eq1
    mov rax,1
cond_eq1:
    push rax
    pop rax
    cmp rax,0
    je else_no2
    push QWORD [rbp-8]
    pop rsi
    call _print_ent
    jmp fin_if2
else_no2:
fin_if2:
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbx
    pop rbp
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
