[bits 32]
[extern startkernel]

global _start

_start:
 ; Define calling point. Must have same name as kernel.c 'main' function
call startkernel ; Calls the C function. The linker will know where it is placed in memory
jmp $
