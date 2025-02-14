; you can put here an ASM function called by C functions according to the ABI standard

						AREA asm_function, CODE, READONLY

						export asm_func
asm_func				proc
	
						;mov   	r12, sp IN CASE OF >4 PARAMETERS
						push 	{r4-r8, r10-r11, lr}
						;ldr   	r4, [r12]
						;ldr   	r5, [r12,#4]
						;ldr   	r6, [r12,#8]
		
						
						
						pop 	{r4-r8, r10-r11, pc}
						endp
						end
