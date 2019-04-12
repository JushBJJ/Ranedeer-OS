#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include <types.h>

/* Malloc */
static char Block[100000]; //100000 bytes = 100KB
//static size_t Next_Index=0;

/*struct Malloc_Block{
  size_t size;
  int free;
  struct Malloc_Block *next;
};
struct Malloc_Block *Free_List=(void*)mem;*/

/* Functions */

void* memcpy(void *dest, void *src,size_t n);
void* memset(void *dst,int c,size_t n);
void initialize();

void *malloc(int Bytes);
void split(struct Malloc_Block *Fitting_Slot_Size,size_t size);
void merge();
void free(void* ptr);
void malloc2(char *a,size_t size);

/* MEMCP IS OLD AND ONLY USED FOR screen.c */
void memcp(u8 *source,u8 *destination,int bytes);
#endif
