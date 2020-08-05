; section .text
; 	global ft_stcmp

; section .data
; 	len	equ	

global	ft_write
	extern	__errno_location

ft_write:
	xor		rax, rax
	xor		rcx, rcx
	push	rsi
	mov		rsi, 1		;Value of the cmd F_GETFD, return fd flags, for fcntl
	mov		rax, 72		;syscall fctnl
	syscall
	pop		rsi
	mov		rax, 1		;syscall write
	syscall
	ret