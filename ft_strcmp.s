section .text
	global ft_strcmp

ft_strcmp:
	xor		rcx, rcx
	jmp		compare

compare:
	cmp		BYTE [rdi + rcx], 0
	je		return
	cmp		BYTE [rsi + rcx], 0
	je		return
	mov		dl, [rdi + rcx]
	cmp		dl, [rsi + rcx]
	jne		return
	inc		rcx
	jmp		compare

return:
	mov		rax, [rdi + rcx]
	and		rax, 255
	mov		rdx, [rsi + rcx]
	and		rdx, 255
	sub		rax, rdx
	ret
