#include <string.h>
#include <stdio.h>
#include <isr.h>

void startkernel(){
  clear();
  for(;;){
    printo("> ");
    SetCursorBarrierHere();
    if(input()){
      if(!strcmp(IN->__IN__,"END")){
        printo("Halt.\n");
        asm("hlt");
      }
      else
        printo("Nope\n");
    }
  }
}
