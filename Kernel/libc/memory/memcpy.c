#include <types.h>

void *memcpy(void *dest, void *src,size_t n){
  char* _dest=dest;
  char* _src=src;
  while(n){ /* While n!=0 */
    *_dest++=*_src;
    n--;
  }
  return _dest;
}
