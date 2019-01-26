#include <string.h>
#include <keyboard.h>
#include <stdio.h>
#include <Kernel.h>
#include <__IN__.h>

void BackspaceChar(){
  __IN__[__pointer]='\0';
  if(__pointer>0)
    __pointer--;
  else
    __pointer=0;

  printo("\n__IN__: %s\n__POINTER: %d\n",__IN__,__pointer);
}
