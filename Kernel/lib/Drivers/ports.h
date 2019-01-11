#ifndef PORTS_H
  #define PORTS_H
  unsigned char PBI(unsigned short port);
  void PBO(unsigned short port, unsigned char data);
  unsigned short PWI(unsigned short port);
  void PWO(unsigned short port, unsigned short data);
#endif
