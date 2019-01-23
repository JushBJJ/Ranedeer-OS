void *memset(void *dst,int c,unsigned int n){
  char* _dst=dst;
  while(n--){
    *_dst++=(char)c;
  }
  return _dst;
}
