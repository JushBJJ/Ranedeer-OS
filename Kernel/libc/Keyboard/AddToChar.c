#include <keyboard.h>
#include <string.h>
#include <stdio.h>
#include <__IN__.h>

void AddtoChar(char c){
  __IN__[__pointer]=c;
  __pointer++;
  __IN__[__pointer]='\0';

  printo("\nTOCHAR: %s\nADDTOCHAR: %c\n__POINTER: %d\n",__IN__,c,__pointer);
  printo("TOCHAR__POINTER: %c\n",__IN__[1]);
}
