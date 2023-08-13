	segment .data
g1	dq	0	;numerator
g2	dq	4	;denominator of 4 grades
q	dq	0	;quotient
r	dq	0	;remainder

	segment .text
	global main
main:
	mov	rax, 95
	mov	rbx, 79
	mov	rcx, 89
	mov	rdx, 68	;moves all grade values to a register
	add	rax, rbx
	add rax, rcx
	add rax, rdx	;all grades are totalled up into rax
	
	mov [g1], rax	;move the total of the grades to the numerator
	
	mov edx, 0	;zeroes out the program
	mov ebx, [g2]	;sets divisor
	mov eax, [g1]	;sets numerator
	idiv ebx	;divide by denominator
	mov [q], eax	;eax = is the quotient
	mov [r], edx	;edx = the remainder
	
	xor eax, eax
	ret
