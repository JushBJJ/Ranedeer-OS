#include <__IN__.h>
#include <screen.h>

void AddtoChar(char c){
  IN->__IN__[IN->__pointer]=c;
  IN->__pointer++;
  IN->__IN__[IN->__pointer]='\0';

  if(IN->__pointer>sizeof(IN->__IN__)){
    Backspace();
    IN->__pointer--;
    return;
  }
}

void BackspaceChar(){
  IN->__pointer--;
  if(IN->__pointer<0)
    IN->__pointer=0;
  IN->__IN__[IN->__pointer]='\0';
}
