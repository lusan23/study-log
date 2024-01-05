// set the odd numbers in the array to 0 
.global _start
.equ endlist, 0xaaaaaaaa
_start:
	ldr r0, =arr
	ldr r3, =endlist
	mov r2, #0
	ldr r1, [r0]
	add r2, r2,r1
loop:
	ldr r1, [r0, #4]! // get the next item address in the list 
	cmp r1, r3 // check if the next item is the end of the list
	beq exit //if the next item is the final of the list... exit it
	add r2, r2, r1 // else r2+= r1
	bal loop
exit:

.data
arr:
	.word 1, 1, 1, 1, 1, 1
