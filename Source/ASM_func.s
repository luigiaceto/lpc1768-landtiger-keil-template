;						AREA output_data, READWRITE
;						
;						export BEST_3
;BEST_3					SPACE 3	


						AREA asm_function, CODE, READONLY
						
;pool                	DCD 4642, 1543, 234, 123, 25642, 34, 3564
						
						export asm_func
asm_func				proc
	
						;mov   	r12, sp NEL CASO DI >4 PARAMETRI -> anche se i parametri sono su meno di 32bit (char, halfword etc) sullo stack vengono allocati 32bit a parametro
						push 	{r4-r8, r10-r11, lr}
						;ldr   	r4, [r12]
						;ldr   	r5, [r12,#4]
						;ldr   	r6, [r12,#8]
						
; MEMORY:
;
; LDR/STR 32bit (int/unsigned int, float, double) -> #4 di offset per scandire un vettore
; LDRB/STRB 8bit (char/unsigned char) -> #1 di offset per scandire un vettore
; LDRH/STRH 16bit -> #2 di offset per scandire un vettore
; LDR r0, [r2, #off] aggiorno r2 e poi carico in r0
; LDR r0, [r2], #off carico in r0 e poi aggiorno r2
; SPACE riserva blocchi azzerati
; LTORG assegna lo starting point di un literal pool
; DCB define constant byte
; DCW define constant half-word -> 2 byte
; DCWD define constant half-word unaligned
; DCD define constant word -> 4 byte
; DCDU define constant word unaligned
						
						
						pop 	{r4-r8, r10-r11, pc}
						endp
						end

; CONDITION FIELD:
;
; EQ - NE - HS(unsigned higher or same) - LO(unsigned lower) - MI(negative) - PL(positive or zero) - VS(overflow)
; VC(no overflow) - HI(unsigned higher) - GT(>) - LE(<=) - GE(>=) - LT(<)
;
; Per poter aggiornare i flag postporre 'S' dopo il nome dell'operazione da eseguire.


; COMANDI DI ALU:
;
; TST and e aggiorna tutti i flag a parte V
; TEQ eor " "
; MUL su 32 bit
; UMULL Rd1, Rd2, Rn, Rm risultato su 64 bit
; UDIV
; SDIV
; AND
; ORR
; EOR
; MVN è il not
; LSL Rd, Rn, op2 logical shift left


; COMANDI DI BRANCH E LDR:
;
; LDR Rd, =constant
; MOV RD, #constant
; ADR Rd, label

						AREA sort, CODE, READONLY
						
						export bubble_sort
bubble_sort				proc
						push 	{r4-r8, r10-r11, lr}
						
						;r0=addrVETT r1=N
						; ATTENZIONE!!! si sta ordinando in maniera decrescente -> invertire r8 ed r10 nella cmp per ordinamento crescente
						mov		r6, #0 ;i
						sub		r1, r1, #1 ;i<n-1

outer_loop				mov		r5, #0 ;j
						sub		r11, r1, r6 ;j<n-1-i
						mov		r7,	r0 ;addrVETT 
					
inner_loop					mov		r4, r7 ;addr VETT[j]
							ldr		r8, [r7], #4 ;VETT[j]
							ldr		r10, [r7] ;VETT[j+1]
							cmp		r8, r10 ;se vett[j]>vett[j+1]
							bge 	skip_swap
							str		r10, [r4] ;arr[j+1]=arr[j]
							str		r8, [r7] ;arr[j]=arr[j+1]
skip_swap					add		r5, r5, #1 ;j++		
							cmp		r5, r11 
							blt 	inner_loop
						
						add		r6, r6, #1 ;i++
						cmp		r6, r1
						blt		outer_loop
						
						pop 	{r4-r8, r10-r11, pc}
						endp
						end


						AREA divisione_manuale, CODE, READONLY

						export divisione
divisione				proc
						push 	{r4-r8, r10-r11, lr}
						
						mov		r4, #50 ;dividendo
						mov		r5, #10 ;divisore
						mov		r6, #0 ;risultato (il resto della divisione viene ignorato)
			
div_loop				cmp		r4, r5
						blt		div_finish ;se il dividendo rimasto è minore del divisore finisci e ignora il resto
						sub		r4, r4, r5
						add		r6, r6, #1
						b		div_loop
				
div_finish
								
						pop 	{r4-r8, r10-r11, pc}
						endp
						end
							
;definizione area dati readONLY
;				AREA _data, DATA, READONLY, align=3
;					EXPORT my_vector [DATA]
;					EXPORT my_variable
;my_vector			DCD -5, 0xFFFFFF01
;my_variable			DCB 'A'
;
				;definizione area dati readWRITE
;				AREA _data2, DATA, READWRITE, align=3
;					EXPORT my_space_4_vector
;my_space_4_vector	SPACE    11*22 ;length(11)*n_byte(22)
;					
;				END