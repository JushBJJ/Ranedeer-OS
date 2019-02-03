#include <types.h>

void *memset(void *dst,int c,size_t n){
  char* _dst=dst;
  while(n--){
    *_dst++=(char)c;
  }
  return _dst;
}
