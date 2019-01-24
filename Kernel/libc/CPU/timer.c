#include <timer.h>
#include <screen.h>
#include <string.h>
#include <isr.h>
#include <ports.h>
u32 tick=0;

static void TimerCallback(registersT regs){
  tick++;
}

void initTimer(u32 freq){
  RegisterInterruptHandler(IRQ0,TimerCallback);
  u32 divisor=1193180/freq;
  u8 low=(u8)(divisor&0xFF);
  u8 high=(u8)((divisor>>8)&0xFF);

  PBO(0x43,0x36);
  PBO(0x40,low);
  PBO(0x40,high);
}
