	segment .data
a	dq	3
b	dq	12

	segment .text
	global main
main:
	mov edx, 0	;sets to 0
	mov eax, [b]	;sets numerator to 12
	mov ebx, [a]	;sets divisor to 3
	idiv ebx	;divide by 3
	
	;eax now equals 4
	
	xor eax, eax
	ret