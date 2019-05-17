	.file	"exo3.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC1:
	.string	"%.10f sec\n"
	.text
	.globl	print_time
	.type	print_time, @function
print_time:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 48
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -28[rbp], esi
	mov	QWORD PTR -40[rbp], rdx
	call	clock@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	ecx, DWORD PTR -28[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR -40[rbp]
	mov	esi, ecx
	mov	rdi, rdx
	call	rax
	mov	DWORD PTR -12[rbp], eax
	call	clock@PLT
	sub	rax, QWORD PTR -8[rbp]
	test	rax, rax
	js	.L2
	cvtsi2ss	xmm0, rax
	jmp	.L3
.L2:
	mov	rdx, rax
	shr	rdx
	and	eax, 1
	or	rdx, rax
	cvtsi2ss	xmm0, rdx
	addss	xmm0, xmm0
.L3:
	movss	xmm1, DWORD PTR .LC0[rip]
	divss	xmm0, xmm1
	cvtss2sd	xmm0, xmm0
	lea	rdi, .LC1[rip]
	mov	eax, 1
	call	printf@PLT
	mov	eax, DWORD PTR -12[rbp]
	leave
	ret
	.size	print_time, .-print_time
	.globl	construit_tableau
	.type	construit_tableau, @function
construit_tableau:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -28[rbp], esi
	mov	DWORD PTR -4[rbp], 0
	jmp	.L6
.L7:
	call	rand@PLT
	mov	ecx, eax
	mov	edx, -1518422781
	mov	eax, ecx
	imul	edx
	lea	eax, [rdx+rcx]
	sar	eax, 6
	mov	edx, eax
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	imul	eax, eax, 99
	sub	ecx, eax
	mov	eax, ecx
	mov	edx, DWORD PTR -4[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*4]
	mov	rdx, QWORD PTR -24[rbp]
	add	rdx, rcx
	add	eax, 1
	mov	DWORD PTR [rdx], eax
	add	DWORD PTR -4[rbp], 1
.L6:
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -28[rbp]
	jl	.L7
	nop
	leave
	ret
	.size	construit_tableau, .-construit_tableau
	.globl	fct1
	.type	fct1, @function
fct1:
	push	rbp
	mov	rbp, rsp
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -28[rbp], esi
	mov	DWORD PTR -8[rbp], 0
	mov	DWORD PTR -4[rbp], 0
	mov	DWORD PTR -8[rbp], 0
	jmp	.L9
.L11:
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	cmp	eax, 24
	jle	.L10
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	cmp	eax, 50
	jg	.L10
	add	DWORD PTR -4[rbp], 1
.L10:
	add	DWORD PTR -8[rbp], 1
.L9:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -28[rbp]
	jl	.L11
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	ret
	.size	fct1, .-fct1
	.globl	fct2
	.type	fct2, @function
fct2:
	push	rbp
	mov	rbp, rsp
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -28[rbp], esi
	mov	DWORD PTR -8[rbp], 0
	mov	DWORD PTR -4[rbp], 0
	mov	DWORD PTR -8[rbp], 0
	jmp	.L14
.L16:
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	cmp	eax, 50
	jg	.L15
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	cmp	eax, 24
	jle	.L15
	add	DWORD PTR -4[rbp], 1
.L15:
	add	DWORD PTR -8[rbp], 1
.L14:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -28[rbp]
	jl	.L16
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	ret
	.size	fct2, .-fct2
	.section	.rodata
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	edi, 4000000
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	cmp	QWORD PTR -8[rbp], 0
	jne	.L19
	mov	edi, 1
	call	exit@PLT
.L19:
	mov	rax, QWORD PTR -8[rbp]
	mov	esi, 1000000
	mov	rdi, rax
	call	construit_tableau
	mov	rax, QWORD PTR -8[rbp]
	lea	rdx, fct1[rip]
	mov	esi, 1000000
	mov	rdi, rax
	call	print_time
	mov	esi, eax
	lea	rdi, .LC2[rip]
	mov	eax, 0
	call	printf@PLT
	mov	rax, QWORD PTR -8[rbp]
	lea	rdx, fct2[rip]
	mov	esi, 1000000
	mov	rdi, rax
	call	print_time
	mov	esi, eax
	lea	rdi, .LC2[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1232348160
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
