extern printf

extern scanf

section .bss
    globals resb 8

section .data
    je_suis_un_connard dq 0
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

sum:
    push rbp
    mov rbp, rsp
    push QWORD [rbp+24]
    push QWORD [rbp+16]
    push QWORD [rbp-8]
    push QWORD [rbp-16]
    pop rcx
    pop rax
    add rax, rcx
    push rax
    pop rax
    jmp fin_sum
fin_sum:
    pop rbx
    pop rbx
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
    push QWORD 0
    push QWORD 1
    mov QWORD [je_suis_un_connard], QWORD 1
    pop rcx
    push QWORD [je_suis_un_connard]
    pop rsi
    call _print_ent
    push QWORD [je_suis_un_connard]
    push QWORD 10
    call sum
    pop rbx
    pop rbx
    push rax
    pop rsi
    call _print_ent
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
