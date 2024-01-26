prf ax, [bx]
cmp ax, 0
jmp end
end:
	cmp ax, 0
	je tes
rel:
	add ax, 1
	mul ax, 8
	cmp ax, 2
	je end
	cmp ax, 8
	je tes
tes:
	add ax, 1
	mul ax, 8
ret ax