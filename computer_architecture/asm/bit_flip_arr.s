//code for ARMv7 (32bits), this code can be compiled at https://cpulator.01xz.net/?sys=arm-de1soc
//algorithm that takes an list of 0 and flip them to 1
.global _start
_start:
	ldr r0, =list //load the first item in the list 
	ldr r1, [r0] // moves the value to register 01
	mvn r1, r1 // flips all the bits in the register
	and r1, r1, #0x00000001 // fixes the the the flipped left zeros
	str r1, [r0], #4 // store it in the stack/memory and moves r1 to point to the next value

	ldr r1, [r0] // moves the value to register 01
	mvn r1, r1 // flips all the bits in the register
	and r1, r1, #0x00000001 // fixes the the the flipped left zeros
	str r1, [r0], #4
	
	ldr r1, [r0] // moves the value to register 01
	mvn r1, r1 // flips all the bits in the register
	and r1, r1, #0x00000001 // fixes the the the flipped left zeros
	str r1, [r0], #4
	
	ldr r1, [r0] // moves the value to register 01
	mvn r1, r1 // flips all the bits in the register
	and r1, r1, #0x00000001 // fixes the the the flipped left zeros
	str r1, [r0], #4
	
.data
list:
	.word 0,0,0,0
