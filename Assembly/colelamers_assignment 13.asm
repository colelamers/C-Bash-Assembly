	segment .data
	dbl dq 21.5
	signed db 0
	fraction dq 0
	exponent dw 0

        segment .text
        global main
main:
	mov rax, [dbl]
	rol rax, 1 ;rotate left to just get the signed bit
	and rax, 0x1 ;zero it out and just get the signed bit
	mov [signed], al ;move signed bit to our variable
	mov rbx, [signed]

	mov rax, [dbl]
	rol rax, 12	;rotates out 12 to get the exponent
	and rax, 2047	;zeroes out that section for the exponent
	sub rax, 1023	;subtracts the fraction bit
	mov [exponent], ax ;moves the exponent into memory
	mov rcx, [exponent]

	mov rax, [dbl] 
	shl rax, 12	;shifts out the exponent and signed bit
	shr rax, 12	;shifts it back into place
	bts rax, 52	;sets the bits
	mov [fraction], rax	;moves the fraction value into memory
	mov rdx, [fraction]

	xor rax, rax
	ret
