#include <string.h>
#include <memory.h>

/* From `man strcpy` */
char *strncpy(char *Origin, char *Copied, size_t SizeOfString){  
  for(size_t i=0; i<SizeOfString+1; i++){
    Origin[i]=Copied[i];
  }
  
  Origin[0+strlen(Origin)]=0x00;
  return Origin;
}

char *strcpy(char *Origin,char *Copied){
  dest = strncpy(Origin, Copied, strlen(Copied);
  return dest;
}
