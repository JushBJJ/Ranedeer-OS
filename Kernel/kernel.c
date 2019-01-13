#include <io/Ranedeerio.h>

char IN[1000];

void startkernel(){
  clear();
  isr_install();
  irq_install();
}
