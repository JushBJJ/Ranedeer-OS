#ifndef IDT_H
  #define IDT_H

  #include <other/types.h>

  #define KernelCS 0x08

  typedef struct{
    u16 lowoffset;
    u16 sel;
    u8 always0;
    u8 flags;
    u16 highoffset;
  }
  __attribute__((packed)) idtgatet;

  typedef struct{
    u16 limit;
    u32 base;
  }
  __attribute__((packed)) idtregistert;

  #define IDTENTRIES 256
  idtgatet idt[IDTENTRIES];
  idtregistert idtreg;

  void SetIdtGate(int n, u32 handler);
  void SetIdt();
#endif
