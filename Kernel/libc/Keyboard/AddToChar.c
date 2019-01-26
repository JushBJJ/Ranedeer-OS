#include <__IN__.h>

void AddtoChar(char c){
  __IN__[__pointer]=c;
  __pointer++;
  __IN__[__pointer]='\0';
}

void BackspaceChar(){
  __pointer--;
  if(__pointer<0){
    __pointer=0;
  }
  __IN__[__pointer]='\0';
}
