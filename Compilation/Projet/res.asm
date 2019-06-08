extern printf

extern scanf

   __size___tab__ dq 8
    format_ent db "%d", 10, 0
    format_long db "%ld", 10, 0
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
    int 80h

_start:
    call main
    jmp _end

main:
    push rbp
    mov rbp, rsp
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 0
    push QWORD 1
    push QWORD 1
    pop rdx
    pop rdx
    push QWORD 10
    pop rcx
    push QWORD 1
    push QWORD 1
    pop rdx
    pop rdx
    pop rsi
    call _print_ent
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbx
    pop rbx
    pop rbx
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
