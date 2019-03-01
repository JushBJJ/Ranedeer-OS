[bits 32]
[extern startkernel]

global _start

_start:
	call startkernel

jmp $
