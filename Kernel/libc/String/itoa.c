#include <types.h>

char *itoa(int val){
  uint8_t *ptr;
  static uint8_t buffer[16];
  ptr=buffer+sizeof(buffer);
  *--ptr='\0';
  if(val==0){
    *--ptr='0';
  }
  else while(val!=0)
  {
    *--ptr=(val%10)+'0';
    val=val/10;
  }
  return((char*)ptr);
}
