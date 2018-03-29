	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_f
	.p2align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -20(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$2, -20(%rbp)
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movslq	-20(%rbp), %rax
	movl	$0, -16(%rbp,%rax,4)
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB0_1
LBB0_4:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_6
## BB#5:
	addq	$32, %rsp
	popq	%rbp
	retq
LBB0_6:
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
