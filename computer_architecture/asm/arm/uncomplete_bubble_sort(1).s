//bubble sort
.global _start
empty_addr: .equ 0xaaaaaaaa
_start:
	ldr r0, =arr		// list 
	ldr r1, [r0]		// current item
	ldr r2, [r0, #4]	//next item
	ldr r4, =empty_addr
	mov r3, #0			//full sorted flag
	ldr r5, =arr  		// verification pointers
	mov r6, r5	//
	add r6, #4
	
	bl bubble_sort
	bl exit


bubble_sort:
	bl sort_step
	bx lr
is_sorted:
//verifies if arr is sorted 
	cmp r6, r4
	beq exit
	cmp r5, r6
	movgt r3, #0
	movlt r3, #1

sort_step:	
	cmp r3, r4  // if full sorted flag equal 1, stop the algorithm
	beq is_sorted			 //compare current item to 
	cmp r1, r2			 // if currt item > next item, switch them
	bgt swap_items
	addlt r0, #4		 // else move the current item and next item foward 					
	addlt r1, #4


swap_items:
// set the flag to sorted and swap items
	str r2, [r0]		
	str r1, [r0, #4]

.data 
arr:
	.word 5, 4, 3, 2 ,1 
	
exit:
