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
    push 0
    mov rax, 0
    mov rdi, 0
    mov rsi, rsp
    mov rdx, 1
    syscall
   pop rax
    ret

_reade:
    mov rax, 0
    mov rdi, format_sent
    call scanf
    pop rax
  ret

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
     push QWORD 0
     push QWORD 0
     push QWORD 0
    push QWORD 0
    push QWORD 1
    pop rax
    imul QWORD [__size___tab__]
    mov QWORD rbx, rax
    pop rax
    imul QWORD [__size___tab__]
    push QWORD 5
     pop rdx
     imul rdx
     add rbx, rax
    mov rax, rbx
     mov rbx, rbp
      add rax, 8
      sub rbx, rax
    push QWORD [rbx]
    pop rcx
    push QWORD [rbp-136]
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
    pop rbx
    pop rbx
    pop rbx
    pop rbp
    ret

_end:
    mov rdi, rax
    mov rax, 60
    syscall
