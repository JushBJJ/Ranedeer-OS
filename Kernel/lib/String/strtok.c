#include <io/Ranedeerio.h>

static char str[10000];
static int i;

void strtok(char ret[], char delim){

  for(i=0;ret[i]!='\0';i++){
    str[i]==ret[i];
  }

  if(str[0]=='\0'||delim=='\0')
    return;

  i=0;

  while(str[i]!='\0'){
    if(str[i]==delim){
      ret[i++]='\0';
      return;
    }
    ret[i]=str[i];
    i++;
  }
  return;
}
