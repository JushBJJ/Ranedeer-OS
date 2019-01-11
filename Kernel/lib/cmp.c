#include <Ranedeerio.h>
#include <Drivers/screen.h>

int strcmp(char *Char1, char *Char2){
  int i;
  do{
    i++;
  }
  while(Char1[i]!=0||Char1[i]!='\0');
  i--;
  return Char1[i]-Char2[i];
}
