#ifndef __IN__H
  #define __IN__H
  #include <bool.h>

  struct INPUT{
    char __IN__[1024]; /* 1 kb */
    bool __INPUT_DONE;
    int __pointer;
    int BARRIER;
    struct INPUT *__NEXT;
  };

  void SetCursorBarrier(int offset);
  void SetCursorBarrierHere();
  void DisableCursorBarrier();

  struct INPUT *IN;
#endif
