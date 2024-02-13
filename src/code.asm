prf [ra], rb
mov rb, 0
cmp ra, 0
jmp end
end:
	cmp ra, 0
	je tes
rel:
	add ra, 1
	mul ra, 8
	cmp ra, 2
	je end
	cmp 9, ra
	je tes
tes:
	add ra, 1
	mul ra, 8
ret