#ifndef KEYBOARD_H
  #define KEYBOARD_H
  #include <types.h>
  void initKeyboard();
  void DisableKeyboard();
  void DisableInput();
  void SetCursorBarrier(int offset);
  void EnableKeyboard();
  void EnableInput();
  void AddtoChar(char s[],char c);
  void BackspaceChar(char s[]);
#endif
