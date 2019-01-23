#include <stdio.h>

char IN[1000];

void startkernel(){
  clear();
  isr_install();
  irq_install();
  char *a="abc";
  printf("test %s",a);
}
