#include <stdio.h>
#include <isr.h>
#include <idt.h>
#include <screen.h>

void startkernel(){
  isr_install();
  irq_install();
  clear();

  printo("Hello ","World!\n");
}
