#include <keyboard.h>
#include <string.h>

void AddtoChar(char s[],char c){
  int len=strlen(s);
  s[len]=c;
  len++;
  s[len]='\0';
}
