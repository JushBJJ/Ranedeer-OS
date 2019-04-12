#ifndef __IN__H
  #define __IN__H
  #include <stdbool.h>

  static char INPUT_BLOCK[1024]; // 1 KB
  static int Input_Block_Pointer;

  void SetCursorBarrier(int offset);
  void SetCursorBarrierHere();
  void DisableCursorBarrier();

  struct INPUT *IN;
#endif
