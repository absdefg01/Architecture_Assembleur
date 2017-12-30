.global _start
_start: 
	adr r0,tab	@mettre le pointeur sur le tab
	
	ldr r1,[r0]	@récupérer la valeur r0 
	ldr r2,[r0,#12]	@récupérer la valeur r0+12 positions 	

	str r2,[r0] 	@mettre la valeur r0 dans r2
	str r1,[r0,#12]	@mettre la valeur r0+12 dans r1

exit:	b	exit

tab:	.int	0xA0,0xD0,0x74,0x24

