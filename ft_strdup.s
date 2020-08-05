extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text
	global 	ft_strdup

ft_strdup:
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	call 	malloc wrt ..plt
	cmp		rax, 0
	je		error
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy
	ret

error:
	neg		rax
	mov		rbx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	mov		rax, 0
	ret