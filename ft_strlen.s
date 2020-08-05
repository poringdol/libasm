section	.text
	global ft_strlen

ft_strlen:
	xor		rax, rax			; rax = 0
	jmp		loop

loop:
	cmp		byte [rdi + rax], 0	; if rdi[rax] == 0
	je		return
	inc		rax
	jmp		loop

return:
	ret