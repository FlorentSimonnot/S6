	.file	"ex4.c"
	.intel_syntax noprefix
	.text
	.globl	fib
	.type	fib, @function
fib:
	mov	eax, 1
	cmp	edi, 2
	jg	.L8
	rep ret
.L8:
	push	rbp
	push	rbx
	sub	rsp, 8
	mov	ebx, edi
	lea	edi, -1[rdi]
	call	fib
	mov	ebp, eax
	lea	edi, -2[rbx]
	call	fib
	add	eax, ebp
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
	.size	fib, .-fib
	.globl	fib2_rec
	.type	fib2_rec, @function
fib2_rec:
	mov	eax, edx
	cmp	edi, 2
	jg	.L15
	rep ret
.L15:
	sub	rsp, 8
	lea	edx, [rdx+rsi]
	sub	edi, 1
	mov	esi, eax
	call	fib2_rec
	add	rsp, 8
	ret
	.size	fib2_rec, .-fib2_rec
	.globl	fib2
	.type	fib2, @function
fib2:
	sub	rsp, 8
	mov	edx, 1
	mov	esi, 1
	call	fib2_rec
	add	rsp, 8
	ret
	.size	fib2, .-fib2
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
