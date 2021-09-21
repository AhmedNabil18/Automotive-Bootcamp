	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"Test.c"
	.text
	.global	specialGLobChar
	.section	.mySection,"aw"
	.type	specialGLobChar, %object
	.size	specialGLobChar, 1
specialGLobChar:
	.byte	5
	.comm	globalChar,1,1
	.global	constGlobalChar
	.section	.rodata
	.type	constGlobalChar, %object
	.size	constGlobalChar, 1
constGlobalChar:
	.byte	-68
	.text
	.align	1
	.global	func
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	func, %function
func:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	movs	r2, #188
	ldr	r3, [r7, #4]
	strb	r2, [r3]
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
	.size	func, .-func
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r3, #205
	strb	r3, [r7, #7]
	adds	r3, r7, #7
	mov	r0, r3
	bl	func
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	cmp	r3, #205
	bne	.L3
	ldr	r3, .L6
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #222
	bne	.L3
	ldr	r3, .L6+4
	movs	r2, #255
	strb	r2, [r3]
	b	.L4
.L3:
	ldr	r3, .L6
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #222
	bne	.L4
	movs	r3, #255
	strb	r3, [r7, #7]
.L4:
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	constLocalChar.4149
	.word	globalChar
	.size	main, .-main
	.section	.rodata
	.type	constLocalChar.4149, %object
	.size	constLocalChar.4149, 1
constLocalChar.4149:
	.byte	-34
	.ident	"GCC: (GNU Arm Embedded Toolchain 9-2020-q2-update) 9.3.1 20200408 (release)"
