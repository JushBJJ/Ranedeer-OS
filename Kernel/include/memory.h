#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include <types.h>

/* Functions */

void *memcpy(void *dest, void *src,unsigned int n);
void *memset(void *dst,int c,unsigned int n);
void *malloc(unsigned int size);
void initialize();
void split(struct Malloc_Block *Fitting_Slot_Size,unsigned int size);
void merge();
void free(void *ptr);

/* MEMCP IS OLD AND ONLY USED FOR screen.c */
void memcp(u8 *source,u8 *destination,int bytes);
#endif
