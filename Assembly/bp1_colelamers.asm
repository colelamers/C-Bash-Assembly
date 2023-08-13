segment .data
a	dw	5
b	dw	3
c	dw	6
p1	dw	0
p2	dw	0
p3	dw	0
p4	dw	0

segment .text
global main
main:
mov	ax, [a]	;ax = a
mov	bx, [b]	;bx = b
add	ax, bx		;adds a + b
mov	[p1], ax	; stores a+b in p1

mov	ax, [a]	;ax = a
mov	bx, [b]	;bx = b
sub	ax, bx		;adds a + b
mov	[p2], ax	; stores a+b in p2

mov	ax, [a]	;ax = a
mov	bx, [c]	;bx = c
add	ax, bx		;adds a + b
mov	[p3], ax	; stores a+b in p3

mov	ax, [a]	;ax = a
mov	bx, [c]	;bx = c
sub	ax, bx		;adds a + b
mov	[p4], ax	; stores a+b in p4

mov ax, [p1]
mov bx, [p2]
mov cx, [p3]
mov dx, [p4]	;saves all the values to the registers to print

xor rax, rax
ret
