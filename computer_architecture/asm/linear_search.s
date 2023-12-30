//linear search with argument arr and 2
.global _start
.equ endlist, 0xaaaaaaaa
.equ target, 0x2

_start:
	ldr r0, =arr
	ldr r1, =endlist
	ldr r2, =target
	ldr r3, [r0]
	
loop:
	cmp  r0, r1
	beq exit
	cmp r3, r2
	beq exit
	add r0, #4
	ldr r3,[r0]
	bal loop
	
exit:

found:
	
	
.data 
arr:
	.word 1, 1, 1, 1, 2, 1
	