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
	leaq	-16(%rbp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -24(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	leaq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	addq	$8, %rax
	cmpq	%rax, %rcx
	jae	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	addq	$4, %rcx
	movq	%rcx, -24(%rbp)
	movl	$0, (%rax)
	jmp	LBB0_1
LBB0_3:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_5
## BB#4:
	addq	$32, %rsp
	popq	%rbp
	retq
LBB0_5:
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
