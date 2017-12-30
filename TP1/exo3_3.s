@on considère un tableau tab en mémoire contenant les octets 0xA0,0xD0,0x74, 0x24, écrire un programme qui permute la première et la dernière case du tableau

.global _start
_start:	adr r0,tab
	ldr r1,[r0]
	ldr r2,[r0,#12]
	str r2,[r0]
	str r1,[r0,#12]

exit:	b exit

tab:	.int 0xA0,0xD0,0x74,0x24
