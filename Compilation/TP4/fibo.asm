section .data

section .text			
	
global _start			
						
extern print_registers	
extern print_stacks

_start:
	push rbp
	mov rbp, rsp
	sub rsp, 240 ;pour 30 variables de 8 octets

	xor rax, rax
	xor	rbx, rbx
	xor rcx, rcx
	xor rdx, rdx

	mov qword [rbp - 8], 0
	mov qword [rbp - 16], 1
	mov rax, -3
	mov rbx, -1
	mov rcx, -2

	_loop:
		mov rdx, [rbp + rbx * 8]
		add rdx, [rbp + rcx * 8]
		mov [rbp + rax * 8], rdx
		call print_registers
		dec rax
		dec rbx
		dec rcx
		cmp rax, -30
		je _exit
		jmp _loop


_exit:
	mov rsp , rbp
	pop rbp
	mov rax,1			
	mov rbx,0			
	int 80h				

