#ifndef KEYBOARD_H
  #define KEYBOARD_H
  #include <types.h>
  #include <memory.h>

  static char KeyBuffer[1000];
  static char *RetKB;
  static int ready=0;

  void initKeyboard();
  void DisableKeyboard();
  void DisableInput();
  void SetCursorBarrier(int offset);
  void EnableKeyboard();
  void EnableInput();
  void AddtoChar(char c);
  void BackspaceChar();
#endif
