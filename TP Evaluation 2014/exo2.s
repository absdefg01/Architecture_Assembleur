@ecrire une fonction longueur(chaine) qui calcule la longueur d'une chapine de caractères chaine

.global _start
_start:	adr r2,chaine
	sub r13,r13,#4	@réservation de valeur de retour
	stmfd r13!,{r2}	@paramètre d'entrée
	BL length
	
	add r13,r13,#4
	ldmfd r13!,{r7}
	
exit: b exit

length: stmfd r13!,{r2,r3,r4,r14}
	ldr r2,[r13,#16]
	mov r4,#0

debut:	ldrb r3,[r2],#1
	cmp r3,#0
	beq fin
	add r4,r4,#1	
	b debut

fin:	str r4,[r13,#20]
	ldmfd r13!,{r2,r3,r4,r15}

chaine:	.asciz	"Ba"
