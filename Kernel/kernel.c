#include <stdio.h>
#include <isr.h>
#include <idt.h>
#include <screen.h>
#include <string.h>
#include <keyboard.h>
#include <Kernel.h>
#include <__IN__.h>

void startkernel(){
  EnableInterrupts();
  if(input()){
    if(!strcmp(__IN__,"END")){
      printo("Halt.");
      asm("hlt");
    }
    else
      printo("nope\n");
  }
}
