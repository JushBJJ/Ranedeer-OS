#ifndef SCREEN_H
  #define SCREEN_H

  #define _VMAddress (char *)0xb8000
  #define _MAXROW 25
  #define _MAXCOL 80
  #define _NormalColor 0x0f
  #define _ErrorColor 0xf4
  #define _REGSCREENCTRL 0x3D4
  #define _REGSCREENDATA 0x3D5

  //Functions
  int CR_PRINTO(char *Message,int col, int row);
  void printo(char *message);
  void printnum(int num);
  void SetCursorPosition(int col, int row);
  void clear();
  void Backspace();
  void printc(char c,int num,int col,int row);
  int putchar(char byte, int col, int row, char attr);
  int GetCursorOffset();
#endif
