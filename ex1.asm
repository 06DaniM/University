.686
.model flat, C

.stack 1000h

.data
a dd 0
b dd 0
i dd ?

.code
main proc

mov eax,[a]

mov [i], 0

whileloop: 
cmp eax, 0

jle looping

sub eax, [b]

inc [i]

jmp whileloop

looping: 

main endp
end main
.end