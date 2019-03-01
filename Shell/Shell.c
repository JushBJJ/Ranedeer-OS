#include <Shell.h>
#include <Shell_Commands.h>
#include <stdio.h>
#include <string.h>
#include <__IN__.h>
#include <keyboard.h>

void RestartKeyboard(){
	DisableKeyboard();
	EnableKeyboard();
}

void Start_Shell(){
	/* Variables */
	char *Args[100];

	int x=0;

	/* Declare Comands */
	struct cmdsX{
		char *Call;
		int(*function)();
	};

	struct cmdsX cmds[]={
		{"echo",echo},
	};

	enum{AOC=sizeof(cmds)/sizeof(cmds[0])};

	/* Main */
	
	clear();	
	printo("Welcome To Ranedeer.\n> ");
	SetCursorBarrierHere();
	I_CK->Keyboard=true;
	EnableKeyboard();
	return;
}	

void RecievedInputK(char *input){
	printo("IN: %s\n",input);
	char *commands_arg[1000];
	char INPUT_STORAGE[10000];
        char *cmd=&INPUT_STORAGE[0];


	/*for(int i=0;i<15;i++){
		printo("%c: %d\n",input[i],input[i]);
	}*/
	cmd=strtok(input," ");
	commands_arg[0]=strtok(NULL," ");
	printo("cmd: %s\nCMD_ARG: %s\n",cmd,commands_arg[0]);

	/*for(int i=0;i<7;i++){
		printo("%c: %d\n",cmd[i],cmd[i]);
	}*/
	if(!strcmp(cmd,"ECHO")){
		echo(cmd,commands_arg);
	}

	printo("> ");
	SetCursorBarrierHere();
	RestartKeyboard();
	return;
}
