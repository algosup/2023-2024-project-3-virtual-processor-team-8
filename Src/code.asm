mov ra, [rc]
prf ra, rb
mov rb, 0
cmp rb, 0
jmp rel
ess:
	mov rd, 178
	add rd, 2
	div rd, 2
	ret
nd:
	cmp ra, 0
	je tes
rel:
	add rb, 1
	mul rb, 8
	cmp rb, 2
	je nd
	call ess
tes:
	add rc, 1
	mul rc, 178
	prt rd, ra
end