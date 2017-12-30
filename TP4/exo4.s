.global _start
_start:	mov r1,#46	
	mov r2,#12

	sub r13,r13,#4	@réserver la place de valeur de retour
	stmfd r13!,{r1,r2}
	
	BL pgcd

	add r13,r13,#8
	ldmfd r13!,{r8}

exit:	b exit

pgcd:	stmfd r13!,{r1,r2,r14}
	ldr r1,[r13,#12]	@a
	ldr r2,[r13,#16]	@b
tq:	cmp r2,#0
	beq fin_pgcd

	@réserver les places pour les valeurs de retour
	@quotient et reste
	sub r13,r13,#8
		
	@entrer les paramtres dans div
	stmfd r13!,{r1,r2}
	BL div

	mov r1,r2	@a = b

	add r13,r13,#12
	ldmfd r13!,{r2}	@b = r
	b tq

fin_pgcd:	str r1,[r13,#20]
		ldmfd r13!,{r1,r2,r15}
	
div:
debut:	stmfd r13!,{r1,r2,r3,r14}
	ldr r1,[r13,#16]
	ldr r2,[r13,#20]
	
boucle:	cmp r1,r2
	bcc fin
	sub r1,r1,r2	@reste
	add r3,r3,#1	@quotient
	b boucle

fin:	str r1,[r13,#28]	@reste
	str r3,[r13,#24]	@quotient
	ldmfd r13!,{r1,r2,r3,r15}
		
	

