section .data

list: dq 1, 1, 2, 3, 5, 8, 13, 21, 0

section .text			
	
global _start			
						
extern print_registers	
extern print_stacks

_start:				
	push rbp
	mov rbp, rsp
	sub rsp, 32 ;pour 4 variables de 8 octets

	mov qword [rbp - 8], 0 ;long long MAX = 0
	mov qword [rbp - 16], 1000 ;long long MIN = 1000
	mov qword [rbp - 24], 0 ;long long sum = 0
	mov qword [rbp - 32], 0 ;long long length = 0

	;MAX
	mov rsi, list
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx
	xor rdx, rdx

	_loop:
		mov rax, [rsi + rcx * 8]

		;updates the sum
		add qword [rbp - 24], rax
		
		inc rcx
		
		;quits the loop if elem = 0
		cmp rax, 0
		je _exit

		;inc the length
		inc qword [rbp - 32]

		;updates the max
		cmp rax, [rbp - 8]
		jg _max

		;updates the min
		cmp rax, [rbp - 16]
		jng _min


		jmp _loop


	_max:
		mov [rbp - 8], rax
		jmp _loop

	_min:
		mov [rbp - 16], rax
		jmp _loop

_exit:
	mov rax, [rbp - 8]
	mov rbx, [rbp - 16]
	mov rcx, [rbp - 24]
	mov rdx, [rbp - 32]
	call print_registers
	mov rax,1			
	mov rbx,0			
	int 80h				

