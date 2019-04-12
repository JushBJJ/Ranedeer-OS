#ifndef SCREEN_H
  #define SCREEN_H

  #define _VMAddress (char *)0xb8000
  #define _MAXROW 25
  #define _MAXCOL 80
  #define _NormalColor 0x0f
  #define _ErrorColor 0xf4
  #define _REGSCREENCTRL 0x3D4
  #define _REGSCREENDATA 0x3D5

  #define printf printo

  //Functions
  void SetCursorPosition(int col, int row);
  void clear();
  void Backspace();
  int GetCursorOffset();
  int GetOffset(int col, int row);
  int GetOffsetRow(int offset);
  int GetOffsetCol(int offset);
  void SetCursorOffset(int offset);
#endif
