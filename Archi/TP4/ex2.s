	.file	"ex2.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	sum
	.type	sum, @function
sum:
	test	edi, edi
	jle	.L4
	xor	edx, edx
	xor	eax, eax
	.p2align 4,,10
	.p2align 3
.L3:
	mov	ecx, edx
	imul	ecx, edx
	imul	ecx, edx
	add	edx, 1
	add	eax, ecx
	cmp	edi, edx
	jne	.L3
	rep ret
	.p2align 4,,10
	.p2align 3
.L4:
	xor	eax, eax
	ret
	.size	sum, .-sum
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	sub	rsp, 8
	xor	edx, edx
	xor	eax, eax
	.p2align 4,,10
	.p2align 3
.L8:
	mov	ecx, eax
	imul	ecx, eax
	imul	ecx, eax
	add	eax, 1
	add	edx, ecx
	cmp	eax, 10000000
	jne	.L8
	lea	rsi, .LC0[rip]
	mov	edi, 1
	xor	eax, eax
	call	__printf_chk@PLT
	xor	eax, eax
	add	rsp, 8
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
