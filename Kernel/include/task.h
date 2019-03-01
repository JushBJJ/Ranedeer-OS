#ifndef TASK_H
	#define TASK_H
	#include <types.h>
	extern void initTasking();

	typedef struct{
		uint32_t eax,ebx,ecx,edx,edi,esi,esp,ebp,flags,cr3;
	}Registers;
	typedef struct Task{
		Registers *regs;
		struct Task *next;
	}Task;

	
