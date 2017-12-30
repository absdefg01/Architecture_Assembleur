.global _start
_start:	adr r1,chaine1
	adr r2,chaine2
	mov r3,#5
	add r2,r2,r3
	


chaine1:.asciz "aa"
chaine2:.asciz "bb"

