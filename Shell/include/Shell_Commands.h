#ifndef SHELL_COMANDS_H
	#define SHELL_COMMANDS_H

	int echo(char *Text,char *COMMANDS[]);
	
	struct cmds{
		char *Call;
		int(*function)();
	};

#endif
