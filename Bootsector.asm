loop0:
	jmp loop0

times 510-($-$$) db 0
dw 0xaa55
