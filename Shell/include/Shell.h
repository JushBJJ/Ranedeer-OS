#ifndef SHELL_H
	#define SHELL_H
	#include <types.h>
	#include <stdbool.h>
        #include <__IN__.h>
	static bool SHELL_INPUT=false;	

	void Start_Shell();
	void RecievedInputK(char input[sizeof(IN->__IN__)]);
#endif
