void memcp(char *source,char *destination,int bytes){
  int i;
  for(i=0;i<bytes;i++){
    *(destination+i)=*(source+i);
  }
}
