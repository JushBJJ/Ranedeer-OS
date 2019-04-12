#ifndef __IN__H
  #define __IN__H
  #include <bool.h>

  char INPUT_BLOCK[1024]; // 1 KB
  int Input_Block_Pointer;

  void SetCursorBarrier(int offset);
  void SetCursorBarrierHere();
  void DisableCursorBarrier();

  struct INPUT *IN;
#endif
