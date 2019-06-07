extern printf

extern scanf

section .data
    global1 dq 1
    global2 dq 10
    un equ 1
    deux equ 3
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

magie:
    push rbp
    mov rbp, rsp
    push QWORD [rbp+24]
    push QWORD [rbp+16]
    push QWORD [global1]
    pop rsi
    call _print_ent
    push QWORD [global2]
    push QWORD [rbp-8]
    pop rcx
    pop rax
    add rax, rcx
    push rax
    push QWORD [rbp-16]
    pop rcx
    pop rax
    mov rdx,0
    idiv rcx
    push rdx
    push QWORD un
    pop rcx
    pop rax
    sub rax, rcx
    push rax
    push QWORD [global1]
    pop rcx
    pop rax
    add rax, rcx
    push rax
    pop rax
    jmp fin_magie
fin_magie:
    pop rbx
    pop rbx
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
    push QWORD 2
    push QWORD 6
     push QWORD 0
    push QWORD [rbp-8]
    push QWORD [rbp-16]
    call magie
    pop rbx
    pop rbx
    push rax
    pop QWORD [rbp-24]
    push QWORD [rbp-24]
    pop rcx
    push QWORD [rbp-24]
    push QWORD 0
    pop rcx
    pop rax
    cmp rax,rcx
    mov rax,0
    jne cond_eq0
    mov rax,1
cond_eq0:
    push rax
    pop rsi
    call _print_ent
    push QWORD 10
    pop rdx
    mov QWORD [global1], QWORD rdx
    push QWORD rdx
    pop rcx
    push QWORD [rbp-8]
    push QWORD [rbp-16]
    call magie
    pop rbx
    pop rbx
    push rax
    push QWORD 9
    pop rcx
    pop rax
    cmp rax,rcx
    mov rax,0
    jne cond_eq1
    mov rax,1
cond_eq1:
    push rax
    pop rsi
    call _print_ent
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbx
    pop rbx
    pop rbx
    pop rbp
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
