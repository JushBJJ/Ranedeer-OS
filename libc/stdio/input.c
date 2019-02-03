#include <__IN__.h>
#include <isr.h>

void _input(){
  IN->__INPUT_DONE=true;
}

int input(){
  EnableInterrupts();
  while(IN->__INPUT_DONE==false){

  }
  DisableInterrupts();
  return 1; /* true */
}
