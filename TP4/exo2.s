@écrire un programme div qui reçoit deux entiers en entrée et calcule le résultat (le quotient et le reste) de la division entière de ces 2 paramètres d'entrée, les paramètres seront transmis par la pile

.global _start
_start: mov r1,#10
	mov r2,#3
	sub r13,r13,#8
	stmfd r13!,{r1,r2}
	BL div
	
tq:	cmp r2,#0
	beq fin_pgcd

	mov r1,r2	
	
	add r13,r13,#8
	ldmfd r13!,{r7}
	b 

exit:	b exit

div:
debut:	stmfd r13!,{r1,r2,r3,r14}
	ldr r1,[r13,#16]
	ldr r2,[r13,#20]
	
boucle:	cmp r1,r2
	bcc fin
	sub r1,r1,r2	@reste
	add r3,r3,#1	@quotient
	b boucle

fin:	str r1,[r13,#24]
	str r3,[r13,#28]
	ldmfd r13!,{r1,r2,r3,r15}
		
	

