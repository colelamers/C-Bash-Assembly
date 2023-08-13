	segment .data
a	dq	3
b	dq	4
c	dq	5
q	dq	0	;quotient
r	dq	0	;remainder
num	dq	0
den	dq	0

	segment .text
	global main
main:
	mov	rax, [a]
	imul	rax, rax	;squares rax
	mov	rbx, [b]
	imul	rbx, rbx ;squares rbx
	
	add	rax, rbx	;a^2 + b^2
	mov [num], rax
	
	mov	rbx, [c]
	imul	rbx, rbx
	mov [den], rbx
	
tripleCheck:
	mov edx, 0	;zeroes out the program
	mov ebx, [num]	;sets divisor
	mov eax, [den]	;sets numerator
	;both numerator and denominator position do not matter. if a triple, remainder = 0. if not the remainder will always be greater than 0 because assembly division does not handle decimals unless told to do so and just sets the quotient to 0 but the remainder of the entire numerator
	idiv ebx	;divide by denominator
	mov [q], eax	;eax = is the quotient
	mov [r], edx	;edx = the remainder
	
	cmp edx, 0
	jz	tripleTrue
	
	cmp edx, 0
	jg	tripleFalse

tripleTrue:	
	mov rdx, 0	;sets rdx 0 saving to memory that the triple is true
	jmp end
	
tripleFalse:
	mov rdx, 1	;sets rdx 1 saving to memory that the triple is false
	jmp end
	
end:
	xor eax, eax
	ret
