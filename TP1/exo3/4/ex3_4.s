.global _start
_start: 
	adr r0,ch3	@mettre le pointeur sur le tab
	
	ldrb r1,[r0]	@récupérer la valeur de r0
	ldrb r2,[r0,#1]	@récupérer la valeur de r0+4positions
	ldrb r3,[r0,#2]	@récupérer la valeur de r0+8positions

	@transférer les majusculs en minusculs
	add r1,r1,#32
	add r2,r2,#32
	add r3,r3,#32
	
	@remmetre les minusculs dans r0,r1,r2
	strb r1,[r0]	@mettre la valeur de r0 dans r1
	strb r2,[r0,#1]	@mettre la valeur de r0+4positions dans r2
	strb r3,[r0,#2]	@mettre la valeur de r0+8positions dans r3
	
exit:	b	exit

ch3:	.asciz "AAA"


