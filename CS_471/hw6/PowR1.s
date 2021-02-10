_powR:                                  ## @powR
	.cfi_startproc
	pushq	%rbp <-- Save current base pointer for control link
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp <-- create new base pointer for current activation record
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp <-- ALLOCATE space for current AR
	xorl	%eax, %eax <-- zero out register
	movl	%edi, -8(%rbp) <-- copy value into 'pow' arg in AR
	movl	%esi, -12(%rbp) <-- copy value into 'base' arg in AR
	cmpl	-8(%rbp), %eax <-- pow == 0
	jne	LBB0_2
	movl	$1, -4(%rbp) <-- return 1 if pow ==0
	jmp	LBB0_3
LBB0_2:
	movl	-12(%rbp), %eax <-- copy base into eax
	movl	-8(%rbp), %ecx <-- copy pow into ecx
	subl	$1, %ecx <-- pow -1
	movl	-12(%rbp), %esi <-- copy base into param2
	movl	%ecx, %edi <-- copy pow into param1
	movl	%eax, -16(%rbp) <-- put result into -16(%rbp)
	callq	_powR <-- call PowR recursively
	movl	-16(%rbp), %ecx <-- move result into register
	imull	%eax, %ecx <-- base * powR(pow-1, base)
	movl	%ecx, -4(%rbp) <-- move result into -4(%rbp)
LBB0_3:
	movl	-4(%rbp), %eax <-- return value in -4(%rbp)
	addq	$16, %rsp <-- DEALLOCATE space on stack
	popq	%rbp <-- pop base pointer restoring to previous state
	retq <-- return 
	.cfi_endproc
                                        ## -- End function
