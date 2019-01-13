#ifndef _IO_RANDEER
  #define _IO_RANEDEER

  #include <Drivers/screen.h>
  #include <Drivers/keyboard.h>
  #include <CPU/isr.h>
  #include <CPU/idt.h>
  #include <other/types.h>

  int GetCharSize(char *target);
  int strcmp(char *Char1,char *Char2);
  void input(char To[]);
  void strtok(char str[], char delim);
  void SetToChar(char To[]);
#endif
