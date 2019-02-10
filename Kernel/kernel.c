#include <string.h>
#include <stdio.h>
#include <isr.h>
#include <string.h>

extern void test();

void startkernel(){
  clear();
  /* Interrupt Initialization */
  I_CK->Keyboard=false;
  I_CK->Call=true; /* ON BY DEFAULT */

  EnableInterrupts();
  /*for(;;){
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
  }*/
  //test();
  printo("test\n");
  char x[10]="lol";
  sprintf(x,"aaa");
  printo("%s\n",x);
}
