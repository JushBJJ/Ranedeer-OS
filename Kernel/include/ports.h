#ifndef PORTS_H
  #define PORTS_H
  #include <types.h>
  u8 PBI(u16 port);
  void PBO(u16 port, u8 data);
  u16 PWI(u16 port);
  void PWO(u16 port, u16 data);
#endif
