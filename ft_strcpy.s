section .text
	global ft_strcpy

ft_strcpy:
	xor		rcx, rcx
	jmp		copy

copy:
	cmp		BYTE [rsi + rcx], 0
	jz		return
	mov		dl, BYTE [rsi + rcx]
	mov		BYTE [rdi + rcx], dl
	inc		rcx
	jmp		copy

return:
	mov		BYTE [rdi + rcx], 0
	mov		rax, rdi
	ret