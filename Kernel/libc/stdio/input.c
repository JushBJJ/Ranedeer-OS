#include <__IN__.h>
#include <isr.h>
#include <keyboard.h>
#include <stdio.h>

void _input(){
  IN->__INPUT_DONE=true;
}

int input(){
  	IN->__IN__[0]='\0';
	I_CK->Keyboard=true;
	while(IN->__INPUT_DONE==false){
		if(I_CK->Keyboard==false)
			I_CK->Keyboard=true;
  	}
  	I_CK->Keyboard=false;
  	IN->__INPUT_DONE=false;
  	return 1; /* true */
}
