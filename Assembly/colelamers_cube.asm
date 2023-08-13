segment .data
i	dq	0

segment .text
global main
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 296 	;creates the array of 100 numbers
        mov     rax, 1		;sets the index at 1
while:
        cmp     rax, 100	;compares rax to 100. If rax is less, it continues. If more, it ends.
        jg      end				;jumps to the end if it's greater than 100
        mov     [i], rax		;rax is the i'th value of the loop and gets passed to [i] which contains the array value
        imul    rax, [i]		; i * i
        imul    rax, [i]		; i ^2 * i = i ^3
        mov     rdx, rax	; passing i^3 to rdx
        mov     rax, [i]		;resets rax to the i'th position
        mov     [i+rax*8], rdx ;stores the cubed value to the array
	   inc 	rax				;increments rax
        jmp    while			;jumps back to the while loop
end:
        xor     rax, rax		;0's out rax
        leave
        ret