#include <string.h>
#include <stdio.h>
#include <isr.h>

void startkernel(){
  EnableInterrupts();

  printo("> ");
  if(input()){
    if(!strcmp(__IN__,"END")){
      printo("Halt.");
      asm("hlt");
    }
    else
      printo("nope\n");
  }
}
