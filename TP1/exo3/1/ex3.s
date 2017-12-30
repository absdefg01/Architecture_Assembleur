.global _start
_start: adr r1,var1
	adr r2,var2

	ldr r4,[r1]
	ldr r5,[r2]
	
	adr r6,res
	add r7,r4,r5

	str r7,[r6]
		
		
exit:	b	exit

var1: .int 2
var2: .int 3
res: .int 0
