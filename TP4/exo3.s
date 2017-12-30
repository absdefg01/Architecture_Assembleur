@écrire une fonction fact en assembleur ARM qui calcule la factorielle d'un entier positif sur 4 octets et renvoie sur 4 octets le résultat, vous utiliserez obligatoirement un passage de paramètres par la pile et l'algorithme itératif

.global _start
_start:	mov r1,#5
	sub r13,r13,#4	@réserver la place pour valeur de retour
	stmfd r13!,{r1}

	BL fact

	add r13,r13,#4
	ldmfd r13!,{r7}
exit:	b exit

fact:	
debut:	stmfd r13!,{r1,r2,r3,r4,r14}
	ldr r1,[r13,#20]
	mov r2,#0
	mov r4,#1

boucle:	cmp r2,r1
	beq fin
	add r2,r2,#1	@compteur
	MUL r3,r2,r4
	mov r4,r3
	b boucle
	
fin:	str r4,[r13,#24]
	ldmfd r13!,{r1,r2,r3,r4,r15}
