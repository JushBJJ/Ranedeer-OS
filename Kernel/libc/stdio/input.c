#include <keyboard.h>
#include <screen.h>
#include <signal.h>
#include <stdio.h>
#include <timer.h>
#include <string.h>
#include <Kernel.h>
#include <__IN__.h>
#include <isr.h>

void _input(){
  __INPUT_DONE=true;
}

int input(){
  while(__INPUT_DONE==false){

  }
  DisableInterrupts();

  printo("INPUT: %s\n",__IN__);
  return 1; /* true */
}
