mov ra, 64
mov rb, 2
prt rc, ra
prf re, rc
mul ra, rb
main:
    mov rd, ra
    reduce:
        sub rd, 1
        cmp rd, 100
        jne reduce
    call multiply
    jmp finish
multiply:
    mov rc, 3
    mul rd, rc
    ret
finish:
    end