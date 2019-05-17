	.file	"ex4.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	sum2
	.type	sum2, @function
sum2:
	test	edi, edi
	jle	.L3
	sub	edi, 1
	shr	edi, 2
	lea	eax, 5[rdi+rdi*4]
	add	eax, eax
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	xor	eax, eax
	ret
	.size	sum2, .-sum2
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	xor	eax, eax
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
