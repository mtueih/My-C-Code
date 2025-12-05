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
	.globl	try2
	.type	try2, @function
try2:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	x(%rip), %rax
	movq	%rax, p1(%rip)
	leaq	y(%rip), %rax
	movq	%rax, p2(%rip)
	jmp	.L2
.L3:
	movq	p2(%rip), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, p2(%rip)
	movq	p1(%rip), %rax
	leaq	4(%rax), %rcx
	movq	%rcx, p1(%rip)
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L2:
	movq	p1(%rip), %rdx
	leaq	x(%rip), %rax
	subq	%rax, %rdx
	cmpq	$196, %rdx
	jle	.L3
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	try2, .-try2
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
