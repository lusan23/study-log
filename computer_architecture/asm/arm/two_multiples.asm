// converts 1, 1, 1, 1 to 1, 2, 4, 8
.global _start
_start:
					// r0 - holds the address of previous item
					// r1 - holds the value of previous item and
					// the new value for current value
					// r2 = holds the address of current item
					
	ldr r0, =list 	// get the first item's address in the list
	add r0, #4		// move to the address of the second item
	ldr r1, [r0] 	// get the value of the second item
	lsl r1, #1 		// multiply its value by 2
	str r1, [r0]  	// stores the new value at the second item
	mov r2, r0 		// move the address of the second item to r2
	add r2, #4		// get the next item address of the third item
	
	
	ldr r1, [r0] 	// get the new value at the second item again
	lsl r1, #1      // multiply its value by 2
	str r1, [r2] 	// stores the new value at the current item 	
	add r2, #4		// moves to the fourth item
	add r0, #4		// moves from the second to the third item
	
	ldr r1, [r0] 	// get the new value from the third
	lsl r1, #1      // multiply its value by 2
	str r1, [r2] 	// stores the new value at the current item 	
	add r2, #4		// moves to the fourth item
	add r0, #4
	
	ldr r1, [r0] 	// get the new value at the first item again
	lsl r1, #1      // multiply its value by 2
	str r1, [r2] 	// stores the new value at the current item 	
	add r2, #4		// moves to the fourth item
	add r0, #4
	list:
	.word 1, 1, 1, 1
