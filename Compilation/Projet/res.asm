extern printf

extern scanf

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

test:
    push rbp
    mov rbp, rsp
    push QWORD [rbp+24]
    push QWORD [rbp+16]
    push QWORD [rbp-8]
    pop rsi
    call _print_ent
    push QWORD [rbp-16]
    pop rsi
    call _print_ent
fin_test:
    pop rbx
    pop rbx
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
   push QWORD 10
   push QWORD 20
    push QWORD 16
    pop rsi
    call _print_ent
    push QWORD [rbp-8]
    push QWORD 10
    call sum
    pop rbx
    pop rbx
    push rax
    pop QWORD [rbp-24]
    push QWORD [rbp-24]
    pop rcx
    push QWORD [rbp-24]
    pop rsi
    call _print_ent
    push QWORD [rbp-16]
    push QWORD 20
    call test
    pop rbx
    pop rbx
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbx
    pop rbx
    pop rbx
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
