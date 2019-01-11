void memcp(char *source,char *destination,int bytes){
  int i;
  for(i=0;i<bytes;i++){
    *(destination+i)=*(source+i);
  }
}

void ToAscii(int num,char str[]) {
    int i,sign;
    if((sign=num)< 0){
      num=-num;
    }
    i=0;
    do{
        str[i++]=num%10+'0';
    }while((num/=10)>0);

    if(sign<0){
      str[i++]='-';
    }
    str[i]='\0';
}
