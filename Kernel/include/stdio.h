#ifndef _IO_RANDEER
  #define _IO_RANEDEER

  #include <screen.h>
  #include <keyboard.h>
  #include <isr.h>
  #include <idt.h>
  #include <types.h>
  #include <stdarg.h>
  #include <Kernel.h>
  #include <__IN__.h>

  static size_t s_pointer=0;

  int GetCharSize(char *target);
  void _input();
  int input();
  char *strtok(char str[], char delim);
  void SetToChar(char To[]);
  int CR_PRINTO(char *Message,int col, int row);
  void printnum(int num);
  void printc(char c);
  int putchar(char byte, int col, int row, char attr);
  int putnum(int n,int col, int row, char attr);

  void printo(const char *message,...);
  void vprinto(const char *message,va_list ap);
#endif
