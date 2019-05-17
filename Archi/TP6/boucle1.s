	.file	"boucle1.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d %d\n"
.LC1:
	.string	"%d\n"
	.text
	.p2align 4,,15
	.globl	fonction
	.type	fonction, @function
fonction:
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbp
	push	rbx
	sub	rsp, 24
	cmp	ecx, 2
	jle	.L4
	lea	eax, -3[rcx]
	mov	r13, rdx
	mov	r15, rsi
	mov	r14, rdi
	mov	ebx, 4
	lea	rax, 8[0+rax*4]
	mov	QWORD PTR 8[rsp], rax
	.p2align 4,,10
	.p2align 3
.L3:
	mov	eax, DWORD PTR -4[r15+rbx]
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	DWORD PTR [r14+rbx], eax
	mov	ebp, DWORD PTR 0[r13+rbx]
	xor	eax, eax
	mov	DWORD PTR [r15+rbx], ebp
	mov	r12d, DWORD PTR [r14+rbx]
	mov	ecx, ebp
	add	rbx, 4
	mov	edx, r12d
	call	__printf_chk@PLT
	cmp	rbx, QWORD PTR 8[rsp]
	jne	.L3
	lea	edx, 0[rbp+r12]
.L2:
	add	rsp, 24
	lea	rsi, .LC1[rip]
	mov	edi, 1
	pop	rbx
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	xor	eax, eax
	jmp	__printf_chk@PLT
	.p2align 4,,10
	.p2align 3
.L4:
	xor	edx, edx
	jmp	.L2
	.size	fonction, .-fonction
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	push	r12
	push	rbp
	mov	edi, 40
	push	rbx
	call	malloc@PLT
	mov	edi, 40
	mov	r12, rax
	call	malloc@PLT
	mov	edi, 40
	mov	rbp, rax
	call	malloc@PLT
	mov	rsi, rbp
	mov	rdx, rax
	mov	ecx, 10
	mov	rdi, r12
	mov	rbx, rax
	call	fonction
	mov	rdi, r12
	call	free@PLT
	mov	rdi, rbp
	call	free@PLT
	mov	rdi, rbx
	call	free@PLT
	pop	rbx
	xor	eax, eax
	pop	rbp
	pop	r12
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
