#include <Shell.h>
#include <stdio.h>
#include <string.h>
#include <__IN__.h>
#include <keyboard.h>
#include <timer.h>

/* Info:
 * RestartKeyboard() function resets the input (Basically Disables then Enables the Keyboard
 * EnableKeyboard() function enables the keyboard
 * DisableKeyboard() function disables the keyboard
 *
 */

void Check_Command(){
        if(CC==true){
                CC=false;
                for(int __TEMP_INT__=0;__TEMP_INT__<AOC;__TEMP_INT__++){
                        if(!strcmp(_C_LIST_->__C_CALL,__COMMAND__)){
                                _C_LIST_[__TEMP_INT__].__C_FUNC(arg);
                                cas=true;
                                cmd="";
                                Arg_Num=0;
                                for(int __TEMP_INT_2__=0;__TEMP_INT_2__!=1000;__TEMP_INT_2__)
                                        arg[__TEMP_INT_2__]="\0";

                                return;
                        }
                }
                printo("Unknown Command!\n");
                return;
        }
}


void RestartKeyboard(){
	DisableKeyboard();
	EnableKeyboard();
}

void Start_Shell(){
	clear();
	printo("Welcome to Ranedeer\n");
	printo("> ");
	SetCursorBarrierHere();
	RestartKeyboard();		
	int x=0;
	while(x==0){}
}	

void RecievedInputK(char *input){
	/*******************************/
	for(int i=0;input[i]!='\0',i<sizeof(INPUT_MEM);i++){
		INPUT_MEM[i]=input[i];
		if(i==sizeof(INPUT_MEM)){
			INPUT_MEM[i]='\0';
			break;
		}
	}
	/*******************************/
	
	printo("INPUT: %s\n",INPUT_MEM);
	printo("> ");
	SetCursorBarrierHere();
	A:
	if(cas==true){
	/* Sets __SWITCH__ to false, copies the value of INPUT_MEM into the __COMMAND__ variable then restarts the Keyboard */
		cas=false;
		CC=true;
		strcpy(INPUT_MEM,cmd);
		RestartKeyboard();
		printo("CMD: %s\n",cmd);
		printo("Arguments: ");		
	}
	else if(cas==false){
	/* Checks the Argument first, else implements INPUT_MEM into __ARGUMENT[x] */
		char *tmp;
		strcpy(INPUT_MEM,tmp);
		if(!strcmp(INPUT_MEM,"STOP")){
			CC=true;
			Check_Command();
			cas=true;
			CC=false;
			Arg_Num=0;
			return;
		}
		Arg_Num++;
		RestartKeyboard();
		printo("Arg [%d]: ",Arg_Num);
		SetCursorBarrierHere();
	}
	else{
		cas=false;
		Arg_Num=0;
		goto A;
	}

	return;
}
