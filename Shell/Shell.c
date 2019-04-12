#include <Shell.h>
#include <stdio.h>
#include <string.h>
#include <__IN__.h>
#include <keyboard.h>
#include <timer.h>
#include <memory.h>

/* Info:
 * RestartKeyboard() function resets the input (Basically Disables then Enables the Keyboard
 * EnableKeyboard() function enables the keyboard
 * DisableKeyboard() function disables the keyboard
 *
 */

static char *Input;
static char *Command;
static char *Args;

void Start_Shell(){
	Input=(char *)malloc(1000);
	clear(); // Clear Screen
	
	/* Welcome Message */
	printo("Welcome to Ranedeer\n");
	
	/* Start */
	Start:
		printo("> ");
		SetCursorBarrierHere();
	
		EnableKeyboard();
		m_strcpy(Input,input());
		DisableKeyboard();
	
		Command = strtok(Input,' ',new);
		Args = strtok(Input,' ',old);
	
		printf("Command: %s\nArgs: %s\n",Command,Args);
		goto Start;
}
