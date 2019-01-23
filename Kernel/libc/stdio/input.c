#include <keyboard.h>
#include <screen.h>
#include <signal.h>
#include <stdio.h>
#include <timer.h>
#include <string.h>

int x;

void input(char To[]){
  SetCursorBarrier(GetCursorOffset());
  int sigret=WaitForSignal(SIG_INPUT);

  if(sigret==SIG_INPUT){
    for(int i=0;ToChar[i]!='\0';i++){
      To[i]=ToChar[i];
    }
    for(int i=0;i<sizeof(ToChar);i++){
      ToChar[i]='\0';
    }
    return;
  }
  else
    return;
}

void SetToChar(char *To){
  for(int i=0;To[i]!='\0';i++){
    ToChar[i]=To[i];
    x=i;
  }
  x++;
  ToChar[x]='\0';
}
