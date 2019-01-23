#ifndef MEMORY_H
#define MEMORY_H

  void *memcpy(void *dest, void *src,unsigned int n);
  void *memset(void *dst,int c,unsigned int n);

  /* MEMCP IS OLD AND ONLY USED FOR screen.c*/
  void memcp(char *source,char *destination,int bytes);
#endif
