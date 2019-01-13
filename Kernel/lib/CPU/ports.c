#include <CPU/ports.h>

u8 PBI(u16 port){
  //Port Byte In
  u8 res;
  __asm__("in %%dx,%%al" :"=a" (res) : "d" (port));
  //in=INPUT (Assembly Instruction)
  return res;
}

void PBO(u16 port,u8 data){
  //Port Byte out
  __asm__ __volatile__("out %%al,%%dx" :: "a" (data),"d" (port));
  //out=OUTPUT (Assembly Instruction)
}
u16 PWI(u16 port){
  u8 res;
  __asm__("in %%dx,%%ax" : "=a" (res) : "d" (port));
  return res;
}
void PWO(u16 port, u16 data){
  __asm__ __volatile__("out %%ax,%%dx" :: "a" (data), "d" (port));
}
