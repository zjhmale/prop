	.file	"T3.cc"
gcc2_compiled.:
___gnu_compiled_cplusplus:
.text
	.align 4
.globl _eval__FRC3Exp
_eval__FRC3Exp:
	pushl %ebp
	movl %esp,%ebp
	subl $4,%esp
	pushl %esi
	pushl %ebx
	movl 8(%ebp),%esi
	movl (%esi),%edx
	movswl 8(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 12(%edx),%eax
	call *%eax
	addl $4,%esp
	testl %eax,%eax
	je L71
	movl (%esi),%edx
	movswl 48(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 52(%edx),%eax
	call *%eax
	jmp L79
	.align 4,0x90
L71:
	movl (%esi),%edx
	movswl 16(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 20(%edx),%eax
	call *%eax
	addl $4,%esp
	testl %eax,%eax
	je L73
	movl (%esi),%edx
	pushl $0
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	movl %eax,%ebx
	movl (%esi),%edx
	pushl $1
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	addl %eax,%ebx
	jmp L80
	.align 4,0x90
L73:
	movl (%esi),%edx
	movswl 24(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 28(%edx),%eax
	call *%eax
	addl $4,%esp
	testl %eax,%eax
	je L75
	movl (%esi),%edx
	pushl $0
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	movl %eax,%ebx
	movl (%esi),%edx
	pushl $1
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	subl %eax,%ebx
	jmp L80
	.align 4,0x90
L75:
	movl (%esi),%edx
	movswl 32(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 36(%edx),%eax
	call *%eax
	addl $4,%esp
	testl %eax,%eax
	jne L77
	movl (%esi),%edx
	pushl $0
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%edx
	movl %edx,-4(%ebp)
	call *%edx
	movl %eax,-4(%ebp)
	pushl %eax
	call _eval__FRC3Exp
	movl %eax,%ebx
	movl (%esi),%edx
	pushl $1
	movswl 56(%edx),%eax
	addl %eax,%esi
	movl %esi,-4(%ebp)
	pushl %esi
	movl 60(%edx),%edx
	movl %edx,-4(%ebp)
	call *%edx
	movl %eax,-4(%ebp)
	pushl %eax
	call _eval__FRC3Exp
	movl %eax,-4(%ebp)
	movl %ebx,%eax
	cltd
	idivl -4(%ebp)
	movl %eax,%ecx
	jmp L79
	.align 4,0x90
L77:
	movl (%esi),%edx
	pushl $0
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	movl %eax,%ebx
	movl (%esi),%edx
	pushl $1
	movswl 56(%edx),%eax
	addl %esi,%eax
	pushl %eax
	movl 60(%edx),%eax
	call *%eax
	pushl %eax
	call _eval__FRC3Exp
	imull %eax,%ebx
L80:
	movl %ebx,%eax
L79:
	leal -12(%ebp),%esp
	popl %ebx
	popl %esi
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
.globl _simplify__FG3Exp
_simplify__FG3Exp:
	pushl %ebp
	movl %esp,%ebp
	leal 8(%ebp),%eax
	pushl %eax
	call __T_3co_X1_rewrite__FR3Exp
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
.globl __T_3co_X1_rewrite__FR3Exp
__T_3co_X1_rewrite__FR3Exp:
	pushl %ebp
	movl %esp,%ebp
	subl $48,%esp
	pushl %esi
	pushl %ebx
	movl 8(%ebp),%esi
	leal -44(%ebp),%ebx
	pushl %ebx
	call ___4BURS
	movl $__vt$9_T_3co_X1,-12(%ebp)
	addl $4,%esp
	pushl $0
	leal -48(%ebp),%eax
	pushl %eax
	pushl %esi
	pushl %ebx
	call _labeler__9_T_3co_X1R3ExpRii
	addl $16,%esp
	movl $__vt$9_T_3co_X1,-12(%ebp)
	pushl $2
	pushl %ebx
	call __$_4BURS
	leal -56(%ebp),%esp
	popl %ebx
	popl %esi
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
.globl _labeler__9_T_3co_X1R3ExpRii
_labeler__9_T_3co_X1R3ExpRii:
	pushl %ebp
	movl %esp,%ebp
	movl 16(%ebp),%eax
	movl $1,(%eax)
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
__$_9_T_3co_X1:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax
	movl $__vt$9_T_3co_X1,32(%eax)
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	call __$_4BURS
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
___cl__9_T_3co_X1R3Exp:
	pushl %ebp
	movl %esp,%ebp
	subl $4,%esp
	pushl $0
	leal -4(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%edx
	pushl %edx
	movl 8(%ebp),%edx
	pushl %edx
	call _labeler__9_T_3co_X1R3ExpRii
	movl %ebp,%esp
	popl %ebp
	ret
	.align 2
__vt$9_T_3co_X1:
	.word 0
	.word 0
	.long 4
	.word 0
	.word 0
	.long __$_9_T_3co_X1
	.word 0
	.word 0
	.long _no_cover__4BURS
	.word 0
	.word 0
	.long _clear__4BURS
	.word 0
	.word 0
	.long ___cl__9_T_3co_X1R3Exp
	.align 1
__T_3co_X1_theta_1:
	.word 0
	.word 0
	.word 0
	.word 2
	.align 1
__T_3co_X1_theta_2:
	.word 0
	.word 0
	.word 0
	.word 3
	.align 1
__T_3co_X1_theta_3:
	.word 0
	.word 0
	.word 0
	.word 4
	.align 1
__T_3co_X1_theta_4:
	.word 0
	.word 0
	.word 0
	.word 5
	.align 1
__T_3co_X1_mu_1_0:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_1_1:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_2_0:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_2_1:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_3_0:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_3_1:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_4_0:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
	.align 1
__T_3co_X1_mu_4_1:
	.word 0
	.word 1
	.word 0
	.word 0
	.word 0
	.word 0
