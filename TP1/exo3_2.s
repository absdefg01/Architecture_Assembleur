@on considère un tableau tab en mémoire contenant 3 entiers, écrire un programme qui met le contenu de la base dans la case2 puis le contenu de la case 0 dans la case 1 puis met à 0 la case 0.

.global _start
_start:	adr r0,tab
	ldr r1,[r0]
	ldr r2,[r0,#4]
	mov r4,#0
	str r4,[r0]
	str r1,[r0,#4]
	str r2,[r0,#8]

exit:	b exit

tab:	.int -1,2,7
