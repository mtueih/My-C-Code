	.file	"main.c"
	.text
	.globl	x
	.bss
	.align 32
	.type	x, @object
	.size	x, 200
x:
	.zero	200
	.globl	y
	.align 32
	.type	y, @object
	.size	y, 200
y:
	.zero	200
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.zero	4
	.globl	p1
	.align 8
	.type	p1, @object
	.size	p1, 8
p1:
	.zero	8
	.globl	p2
	.align 8
	.type	p2, @object
	.size	p2, 8
p2:
	.zero	8
	.text
	.globl	try4
	.type	try4, @function
try4:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movl	$0, %ebx
	leaq	x(%rip), %r12
	leaq	y(%rip), %r13
	jmp	.L2
.L3:
	movq	%r13, %rdx
	leaq	4(%rdx), %r13
	movq	%r12, %rax
	leaq	4(%rax), %r12
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, %ebx
.L2:
	cmpl	$49, %ebx
	jle	.L3
	nop
	nop
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	try4, .-try4
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
