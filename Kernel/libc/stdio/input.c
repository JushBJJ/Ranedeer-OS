#include <__IN__.h>
#include <isr.h>

void _input(){
  __INPUT_DONE=true;
}

int input(){
  while(__INPUT_DONE==false){

  }
  DisableInterrupts();
  return 1; /* true */
}
