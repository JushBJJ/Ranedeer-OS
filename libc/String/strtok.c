#include <stdio.h>
#include <string.h>

char *strtok(char *ret, char *delim){
  static char* buffer;
  const char *d;

  if(ret!=NULL)
    buffer=ret;

  if(buffer[0]=='\0')
    return NULL;

  char *x=buffer,*b;
  for(b=buffer;*b!='\0';b++){
    for(d=delim;*d!='\0';d++){
      if(*b==*d){
        *b='\0';
        buffer=b+1;
        if(b==x){
          x++;
          continue;
        }
        return x;
      }
    }
  }
  return x;
}
