@écrire à l'envers une chaînede caractères chaine1 et stocke le dans chaine2

.global _start
_start:	adr r2,chaine	@pointeur de chaine1
	adr r3,chaine2	@pointeur de chaine2
	sub r13,r13,#4	@réservation de valeur de retour
	stmfd r13!,{r2,r3}	@paramètre d'entrée
	
	BL renverse
	
	add r13,r13,#8
	ldmfd r13!,{r7}
	
exit: b exit

length: stmfd r13!,{r2,r3,r4,r14}
	ldr r2,[r13,#16]
	mov r4,#0

debut:	ldrb r3,[r2],#1
	cmp r3,#0
	beq fin_length
	add r4,r4,#1	
	b debut

fin_length: 	str r4,[r13,#20]
		ldmfd r13!,{r2,r3,r4,r15}


renverse:
	stmfd r13!,{r1,r2,r3,r4,r14}
	ldr r1,[r13,#20]	@lire chaine1
	ldr r2,[r13,#24]	@lire chaine2
	sub r13,r13,#4		@réservation de valeur de retour
	stmfd r13!,{r1}		@entrer la paramètre (chaine1)
	bl length		@appel la fonction
	add r13,r13,#4
	ldmfd r13!,{r3}		@dépilier le résultat de length


debut2:	cmp r3,#0	@compteur de longueur
	beq fin
	ldrb r4,[r1],#1
	strb r4,[r2],#-1
	sub r3,r3,#1
	b debut2

fin:	ldmfd r13!,{r1,r2,r3,r4,r15}
	

	
	
	



chaine:	.asciz	"abcc"
chaine2: .asciz	"cc"
