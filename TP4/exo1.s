@écrire un sous programme qui renvoie le max de 2 entiers, les paramètres sont transmis par la pile
.global _start
_start:	sub r13,r13,#4	@réserver la place pour valeur de retour
	mov r1,#2
	mov r2,#10	
	stmfd r13!,{r1,r2}

	BL max

	add r13,r13,#8
	ldmfd r13!,{r7}
	
exit: b exit

max:
debut:	stmfd r13!,{r1,r2,r14}
	ldr r1,[r13,#12]
	ldr r2,[r13,#16]
	cmp r1,r2
	bcs cas
	b fin

cas:	mov r2,r1

fin:	str r2,[r13,#20]
	ldmfd r13!,{r1,r2,r15}
	

