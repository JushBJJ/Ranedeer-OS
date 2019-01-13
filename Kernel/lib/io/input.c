#include <Drivers/keyboard.h>
#include <Drivers/screen.h>
#include <Signal/signal.h>

static char ToChar[256];

void input(char To[]){
  SetCursorBarrier(GetCursorOffset());
  int sigret=WaitForSignal(SIG_INPUT);

  printo("sigret: ");
  printnum(sigret);
  printo("\n");
  if(sigret==SIG_INPUT){
    for(int i=0;ToChar[i]!='\0';i++){
      To[i]=ToChar[i];
    }
    printo(To);
    return;
  }
  else
    printo("Error\n");
}

void SetToChar(char To[]){
  for(int i=0;To[i]!='\0';i++){
    ToChar[i]=To[i];
  }
}
