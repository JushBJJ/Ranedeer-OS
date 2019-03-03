#ifndef SHELL_H
	#define SHELL_H
	#include <types.h>
	#include <stdbool.h>
        #include <__IN__.h>
	
	/* Variables and Memory */

	// Memory
        char COMMAND_MEM[1000]; //1000 bytes
        char INPUT_MEM[1000]; //1000 bytes
        char *INPUT_REAL=&INPUT_MEM[0]; //input variable will be stored in this variable next..

    /* Required Variables */
        static char *__COMMAND__;
        static char *__ARGUMENT__[1000]; // Up to 1000 Arguments
        static bool __SWITCH__;
        static bool Check_Command__;
        static int Arg_Num=0;
        #define cas __SWITCH__ //Command-Argument-Switch
        #define cmd __COMMAND__
        #define arg __ARGUMENT__
        #define CC Check_Command__

        //Flaw of the argument variable, 1000 Arguments but not enough possible memory???

        /*
         * __COMMAND__ (true)
         * __ARGUMENT__ (false)
         */



	/* Other stuff */

	void echo(char *Text,char *COMMANDS[]);

	struct _C_{
		char *__C_CALL; // _C_ means _COMMAND_
		void (*__C_FUNC)(); // COMMAND_FUNCTION
	};
	struct _C_ _C_LIST_[]={
		{"ECHO",echo}
	};
	enum{AOC=sizeof(_C_LIST_)/sizeof(_C_LIST_[0])};


	static bool SHELL_INPUT=false;	

	void Start_Shell();
	void RecievedInputK(char input[sizeof(IN->__IN__)]);
#endif
