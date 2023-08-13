	segment .data
a	dq	0
b	dq	0
q	dq	0
r	dq	0
gcd	dq	0
gcdb	dq	0

	segment .text
	global main
main:
;This would contain the data that would ask for parameters
;Would also conduct a loop of some kind most likely
;In my segment .data, a and b would most likely be the numbers being checked for gcd
;Here it would continue for the second gcd of a number when that happens...
mov [gcdb], [gcda]	; this then moves the current GCD value to gcdb. 
;assuming the program jumps back into the recursive function call again, gcda is ready to be reused
;flag check to continue running. if ti fails, then it eventually exits the program hitting xor rax, rax
	xor rax, rax
	ret
	
gcdCheck:
cmp	[gcdb], [q]
jz	updateGCDa	;if the quotient compared to the saved/current gcd do not equal zero, gcda does not get updated (which eventually gets placed in gcdb). This catches for the actually GCD of two nubmers
call gcdRecursiveFunction	;loops back to the recursive function

updateGCDa:
mov	[gcda], [q]					;updates the value of gcda to the newest quotient received
call gcdRecursiveFunction	;loops back to the recursive function

call	gcdRecursiveFunction

gcdRecursiveFunction:
	mov rdx, 0	;zeroes out the divisor
	mov rbx, [a]	;sets divisor
	mov rax, [b]	;sets numerator
	idiv rbx	;divide by denominator
	mov [q], rax	;[q] = is the quotient
	mov [r], rdx	;[r] = the remainder
	cmp [b], [a]	;compares the denominator b to numerator to a and makes sure denominator is not higher than numerator
	jl	main			;if they are the same, it jumps back to main. This prevents the GCD from being updated yet
	cmp [r], 0		;compares the remainder to 0
	jz	gcdCheck	;if [r] = 0, it updates the GCD of those two numbers
	add [b], 1		;increments the denominator again
	call	gcdRecursiveFunction	;jumps back to the start of gcdRecursiveFunction


	


