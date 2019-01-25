#include <stdio.h>
#include <isr.h>
#include <idt.h>
#include <screen.h>
#include <string.h>

void startkernel(){
  isr_install();
  irq_install();
  clear();

  char *x="World";
  char y='!';
  int i=1337;
  printo("Hello",x,y,i);

  printo("\nHello %s%c%d",x,y,i);
}
