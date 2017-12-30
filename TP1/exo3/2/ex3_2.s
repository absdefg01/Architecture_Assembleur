.global _start
_start: adr r0,tab	@mettre le pointeur sur le tab
	ldr r1,[r0]	@récupérer la valeur r0 
	ldr r2,[r0,#4]	@récupérer la valeur r0+4 positions 
	ldr r3,[r0,#8]	@récupérer la valeur r0+8 positions 
	
	str r2,[r0,#8] 	@mettre la valeur r0+8 dans r2
	str r1,[r0,#4]	@mettre la valeur r0+4 dans r1
	
	mov r4,#0
	str r4,[r0]	@mettre la valeur 0 dans r0

exit:	b	exit

tab:	.int	2,3,4

