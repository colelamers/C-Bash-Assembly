        segment .data
x1      dq      2
y1      dq      4
x2    	dq      10
y2	dq      3
difx	dq	0
dify	dq	0
difx2	dq	0
dify2	dq	0
clen	dq	0
one	dq	1
	
        segment .text
        global  main
main:
	mov 	rbx, [y2]
	sub 	rbx, [y1]
	mov 	[dify], rbx

	xor 	rax, rax

	mov 	rbx, [x2]
	sub 	rbx, [x1]
	cmovz	rax, [one]
	mov 	[difx], rbx

	xor	rbx, rbx
	xor	rax, rax

	mov	rbx, [difx]
	imul	rbx, rbx
	mov	[difx2], rbx
	mov	rcx, [difx2]

	xor	rbx, rbx

	mov	rbx, [dify]
	imul	rbx, rbx
	mov	[dify2], rbx
	mov	rdx, [dify2]

	mov	rax, rdx
	add	rax, rcx
	mov	[clen], rax
	xor	rax, rax
	mov	rax, [clen]

	xor rax, rax
       
        ret
