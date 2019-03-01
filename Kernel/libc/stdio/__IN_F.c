#include <__IN__.h>
#include <stdio.h>
#include <screen.h>
#include <Shell.h>

void AddtoChar(char c){
  IN->__IN__[IN->__pointer]=c;
  IN->__pointer++;
  IN->__IN__[IN->__pointer]='\0';
  
  if(IN->__pointer>sizeof(IN->__IN__)){
    Backspace();
    IN->__pointer--;
  }
  if(c=='\n'){
	  IN->__pointer--;
	  IN->__IN__[IN->__pointer]='\0';
	  RecievedInputK(IN->__IN__);
  }
}

void BackspaceChar(){
  IN->__pointer--;
  if(IN->__pointer<0)
    IN->__pointer=0;
  IN->__IN__[IN->__pointer]='\0';
}

void SendInput(){
	RecievedInputK(IN->__IN__);
	printo("RecievedInput: %s\n",IN->__IN__);
}
