extern printf
extern scanf
extern getchar
global _start

section .data
    display_ent db "%d", 10, 0
    display_long db "%ld", 10, 0
    format_integer db "%d", 0

section .text

_start:	
    call main
    jmp end

_print_car:
    mov rax, 0
    call printf WRT ..plt
    ret

_print_ent:
    mov rdi, display_ent
    mov rax, 0
    call printf WRT ..plt
    ret

_print_long:
    mov rdi, display_long
    mov rax, 0
    call printf WRT ..plt
    ret

_reade:
    mov rdi, format_integer
    mov rax, 0
    call scanf
    ret

somme:
    push rbp
    mov rbp, rsp
    push QWORD [rbp+16]
    push QWORD 0
    push QWORD 0
    push QWORD [rbp-8]
    pop rsi
    call _print_ent
while_no0:
    push QWORD [rbp-16]
    push QWORD [rbp-8]
    pop rcx
    pop rax
    cmp rax, rcx
    mov rax, 1
    mov rax, 0
    jg cond_no0 
    je cond_no0 
    mov rax, 1 
cond_no0:
    push rax
    pop rax
    cmp rax, 0
    je fin_while0
    push QWORD [rbp-16]
    pop rsi
    call _print_ent
    push QWORD [rbp-24]
    push QWORD [rbp-16]
    pop rcx
    pop rax
    add rax, rcx
    push rax
    pop QWORD [rbp-24]
    push QWORD [rbp-24]
    pop rcx
    push QWORD [rbp-24]
    pop rsi
    call _print_long
    push QWORD [rbp-16]
    push QWORD 1
    pop rcx
    pop rax
    add rax, rcx
    push rax
    pop QWORD [rbp-16]
    push QWORD [rbp-16]
    jmp while_no0
fin_while0:
    push QWORD [rbp-24]
    pop rax
    jmp fin_somme
fin_somme:
    pop rbx
    pop rbx
    pop rbx
    pop rbx
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
    push QWORD 0
    push QWORD 10
    call somme
    pop rbx
    push rax
    pop QWORD [rbp-8]
    push QWORD [rbp-8]
    pop rsi
    call _print_long
    push QWORD 0
    pop rax
    jmp fin_main
fin_main:
    pop rbx
    pop rbp
    ret

end:
    mov rax,1
    mov rbx,0
    syscall
