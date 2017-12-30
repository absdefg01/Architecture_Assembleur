@ecrire un programme qui met en minuscule une chaine de 3 caractères chaine3 écrite en majuscule et stockée en mémoire

.global _start
_start:	adr r0,chaine	@pointeur sur la chaîne

debut:	ldrb r1,[r0],#1	@lire les lettres un par un
	cmp r1,#0
	beq exit
	cmp r1,#'a'
	bcs debut

mini:	add r1,r1,#'a'-'A'
	strb r1,[r0,#-1]
	b debut


exit: b exit

chaine:	.asciz "AAAB"
