	segment .data
	
dblstr  	dq	15.35
sign	dq	0
exp	dq	0
fra	dq	0

        segment .text
        global  main
main:
mov	rax, [dblstr] 	;collecting the value in a register
ror	rax,  63	;preserves bits 63-0
shr	ra x, 63
shl	rax, 63
or	
ror	rax, 
shr	rax, 
shl	rax, 
or	rax, rbx
rol	rax, 

