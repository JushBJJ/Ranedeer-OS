#include <string.h>

/* From `man strcpy` */
char *strncpy(char *dest, const char *f,size_t n){
  size_t i;
  for(i=0;i<n&&f[i]!='\0';i++)
    dest[i]=f[i];
  for(;i<n;i++)
    dest[i]='\0';

  return dest;
}

char *strcpy(char *dest,char *f){
  int x=strlen(f);
  strncpy(dest,f,x);
}
