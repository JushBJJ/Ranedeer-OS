#ifndef KEYBOARD_H
  #define KEYBOARD_H
  #include <types.h>
  #include <memory.h>
  #include <__IN__.h>

  static int ready=0;

  void initKeyboard();
  void DisableKeyboard();
  void DisableInput();
  void SetCursorBarrier(int offset);
  void EnableKeyboard();
  void EnableInput();

  void BackspaceChar();
  void AddtoChar(char c);
  void SendInput();
#endif
