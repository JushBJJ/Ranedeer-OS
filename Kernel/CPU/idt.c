#include <idt.h>

void SetIdtGate(int n,u32 handler){
  idt[n].lowoffset=low_16(handler);
  idt[n].sel=KernelCS;
  idt[n].always0=0;
  idt[n].flags=0x8E;
  idt[n].highoffset=high_16(handler);
}

void SetIdt(){
  idtreg.base=(u32)&idt;
  idtreg.limit=IDTENTRIES*sizeof(idtgatet)-1;
  __asm__ __volatile__("lidtl (%0)" : : "r" (&idtreg));
}
