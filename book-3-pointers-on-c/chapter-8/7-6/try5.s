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
	.globl	try5
	.type	try5, @function
try5:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	leaq	x(%rip), %rbx
	leaq	y(%rip), %r12
	jmp	.L2
.L3:
	movq	%r12, %rdx
	leaq	4(%rdx), %r12
	movq	%rbx, %rax
	leaq	4(%rax), %rbx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
.L2:
	leaq	200+x(%rip), %rax
	cmpq	%rax, %rbx
	jb	.L3
	nop
	nop
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	try5, .-try5
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
