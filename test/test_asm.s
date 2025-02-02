	.file	"test_asm.c"
	.option pic
	.text
	.globl	b
	.data
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.word	10
	.section	.rodata
	.align	3
.LC0:
	.string	"hello!"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,1
	sw	a5,-20(s0)
	lla	a0,.LC0
	call	puts@plt
	li	a5,0
	mv	a0,a5
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
