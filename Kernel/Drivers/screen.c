#include <screen.h>
#include <ports.h>
#include <string.h>
#include <Data.h>
#include <stdio.h>
#include <types.h>
#include <stdarg.h>
#include <memory.h>

//Small Functions (Private)
  int GetOffset(int col, int row){
    return 2*(row*_MAXCOL+col);
  }
  int GetOffsetRow(int offset){
    return offset/(2*_MAXCOL);
  }

  int GetOffsetCol(int offset){
    return (offset-(GetOffsetRow(offset))*2*_MAXCOL)/2;
  }

//Public
  void printc(char c){
    CC=GetOffsetCol(GetCursorOffset());
    CR=GetOffsetRow(GetCursorOffset());

    putchar(c,CC,CR,0x0f);
  }

  int CR_PRINTO(char *Message,int col, int row){
    int offset;
    int i=0;

    if(col>=0&&row>=0){
      offset=GetOffset(col,row);
    }
    else{
      offset=GetCursorOffset();
      row=GetOffsetRow(offset);
      col=GetOffsetCol(offset);
    }

    i=0;
    while(Message[i]!=0){
      offset=putchar(Message[i++],col,row,_NormalColor);

      row=GetOffsetRow(offset);
      col=GetOffsetCol(offset);
    }
    return offset;
  }

  void printo(char *message){
    int offset=CR_PRINTO(message,CC,CR);
    CC=GetOffsetCol(offset);
    CR=GetOffsetRow(offset);
  }

  void printf(char *message,...){
    CC=GetOffsetCol(GetCursorOffset());
    CR=GetOffsetRow(GetCursorOffset());

    char *s;
    int i=0;
    int x=0;
    va_list ap;
    va_start(ap,message);
    while(*message){
      switch(*message++){
        case 's':
          s=va_arg(ap,char *);
          printf(s);
          i++;
          break;
        default:
          printc(message[i]);
          i++;
          break;
      }
    }
    va_end(ap);
    CC=GetOffsetCol(GetCursorOffset());
    CR=GetOffsetRow(GetCursorOffset());

  }

  void printnum(int num){
    int offset=putnum(num,CC,CR,_NormalColor);
    CC=GetOffsetCol(offset);
    CR=GetOffsetRow(offset);
  }

  void SetCursorPosition(int col,int row){
    CR_PRINTO(" ",col,row);
  }

  void Backspace(){
    int offset=GetCursorOffset()-2;
    int col=GetOffsetCol(offset);
    int row=GetOffsetRow(offset);

    putchar(0x08,col,row,_NormalColor);
  }
//Private Kernel Functions
int GetCursorOffset(){
  int ret;
  PBO(_REGSCREENCTRL,14);
  ret=PBI(_REGSCREENDATA)<<8;
  PBO(_REGSCREENCTRL,15);
  ret+=PBI(_REGSCREENDATA);
  return ret*2;
}

void SetCursorOffset(int offset){
  offset/=2;

  PBO(_REGSCREENCTRL,14);
  PBO(_REGSCREENDATA,(unsigned char)(offset>>8));
  PBO(_REGSCREENCTRL,15);
  PBO(_REGSCREENDATA,(unsigned char)(offset&0xff));
}

int putnum(int n,int col, int row, char attr){
  int z;

  char s[100000];
  int i,sign,x;
  char c;
  i=0;

  if((sign=n)<0){
    n=n-n;
  }
  do{
    s[i++]=n%10+'0';
  }
  while((n/=10)>0);

  if(sign<0){
    s[i++]='-';
  }
  s[i]='\0';

  i,x=0;
  for(int zx=0;s[i]!=0||s[i]!='\0';i++){
    z=zx;
  }
  for(i=0,x=z;i<x;i++,x--){
    c=s[i];
    s[i]=s[x];
    s[x]=c;
  }
  int offset=CR_PRINTO(s,col,row);
  return offset;
}

int putchar(char byte,int col, int row,char attr){
  u8 *_VMADDR=(u8*)_VMAddress;
  if(!attr){
    attr=_NormalColor;
  }

  if(col>=_MAXCOL||row>=_MAXROW){
    _VMADDR[2*(_MAXCOL)*(_MAXROW)-2]='E';
    _VMADDR[2*(_MAXCOL)*(_MAXROW)-1]=_ErrorColor;
    return GetOffset(col,row);
  }

  int offset;
  if(col>=0&&row>=0){
    offset=GetOffset(col,row);
  }
  else{
    offset=GetCursorOffset();
  }
  if(byte=='\n'){
    row=GetOffsetRow(offset);
    offset=GetOffset(0,row+1);
  }
  else if(byte==0x08){
    _VMADDR[offset]=' ';
    _VMADDR[offset+1]=attr;
  }
  else{
    _VMADDR[offset]=byte;
    _VMADDR[offset+1]=attr;
    offset+=2;
  }

  if(offset>=_MAXROW*_MAXCOL*2){
    int i;
    for(i=1;i<_MAXROW;i++){
      memcp((u8*)(GetOffset(0,i)+_VMADDR),
            (u8*)(GetOffset(0,i-1)+_VMADDR),
            _MAXCOL*2);
    }
    char *lastline=(char*)(GetOffset(0,_MAXROW-1)+(u8*)_VMADDR);
    for(i=0;i<_MAXCOL*2;i++){
      lastline[i]=0;
    }
    offset-=2*_MAXCOL;
  }
  SetCursorOffset(offset);
  CC=col;
  CR=row;
  return offset;
}
void clear(){
  int screensize=_MAXROW*_MAXCOL;
  int i;
  char *screen=_VMAddress;

  for(i=0;i<screensize;i++){
    screen[i*2]=' ';
    screen[i*2+1]=_NormalColor;
  }
  SetCursorOffset(GetOffset(0,0));
}
