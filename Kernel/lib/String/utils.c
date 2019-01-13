#include <String/utils.h>
#include <Drivers/screen.h>
void memcp(char *source,char *destination,int bytes){
  int i;
  for(i=0;i<bytes;i++){
    *(destination+i)=*(source+i);
  }
}

void memset(u8 *dest,u8 val,u32 len){
  u8 *temp=(u8 *)dest;
  for(;len!=0;len--){
    *temp++=val;
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

char ToAsciiRet(int num){
  return (num%10+'0');
}

int strlen(char s[]){
  int i;
  for(i=0;s[i]!='\0';i++){}
  return i;
}

void AddtoChar(char s[],char c){
  int len=strlen(s);
  s[len]=c;
  len++;
  s[len]='\0';
}

void BackspaceChar(char s[]){
  int len=strlen(s);
  s[len-1]='\0';
}
