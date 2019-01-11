#include <CPU/timer.h>
#include <Drivers/screen.h>
#include <utils.h>
#include <CPU/isr.h>
#include <Drivers/ports.h>
u32 tick=0;

static void TimerCallback(registersT regs){
  tick++;
  char TickAscii[256];
  printo("Tick :");
  ToAscii(tick,TickAscii);
  printo(TickAscii);
  printo("\n");
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
