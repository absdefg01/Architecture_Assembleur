@écrire un programme qui à partir de deux entiers tockés dans deux variables en mémoire var1 et var2, en fait la somme et stock le résultat dans une variable en mémoire res

.global _start
_start:	ldr r1,var
	ldr r2,var2
	add r3,r1,r2
	str r3,res

exit:	b exit

var:	.int 2
var2:	.int 5
res:	.int 0
