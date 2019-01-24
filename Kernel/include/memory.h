#ifndef MEMORY_H
#define MEMORY_H
  #include <types.h>
  
  void *memcpy(void *dest, void *src,unsigned int n);
  void *memset(void *dst,int c,unsigned int n);

  /* MEMCP IS OLD AND ONLY USED FOR screen.c*/
  void memcp(u8 *source,u8 *destination,int bytes);
#endif
