#ifndef _IO_RANDEER
  #define _IO_RANEDEER

  #include <screen.h>
  #include <keyboard.h>
  #include <isr.h>
  #include <idt.h>
  #include <types.h>

  char ToChar[100000];
  int GetCharSize(char *target);
  void input(char To[]);
  char *strtok(char str[], char delim);
  void SetToChar(char To[]);
  int CR_PRINTO(char *Message,int col, int row);
  void printnum(int num);
  void printc(char c);
  int putchar(char byte, int col, int row, char attr);
  int putnum(int n,int col, int row, char attr);

  void printo(char *message,...);
  void vprinto(char *message);
#endif
