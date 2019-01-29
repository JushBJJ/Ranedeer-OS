#include <string.h>

int strcspn(char *text,char target){
  int i=0;

  while(text[i]!=target)
    i++;

  if(i==strlen(text))
    return -1;

  return i;
}
