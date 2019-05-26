section .data

section .text           
    
global _start, _int_cmp, _swap

extern print_registers
                        
_start:
	push rbp
	mov rbp, rsp
	
	sub rsp, 8
	mov rdi, rsp

	sub rsp, 8
	mov rsi, rsp
	
	mov rax, rdi
	mov rbx, rsi

	call _swap

	mov rsp, rbp
	pop rbp

	mov rax, 0
	mov rbx, 0 
	int 80h

_swap:
	push rdi
	push rsi
	
	pop rax
	pop rbx
	mov rdi, rax
	mov rsi, rbx