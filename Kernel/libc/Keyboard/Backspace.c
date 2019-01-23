#include <string.h>
#include <keyboard.h>

void BackspaceChar(char s[]){
  int len=strlen(s);
  s[len-1]='\0';
}
