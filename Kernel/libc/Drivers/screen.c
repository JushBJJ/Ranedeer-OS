#include <screen.h>
#include <ports.h>
#include <stdbool.h>
#include <string.h>
#include <Data.h>
#include <stdio.h>
#include <types.h>
#include <stdarg.h>
#include <memory.h>

//Small Functions (Private)
  int C_Size(char *s);

  int GetOffset(int col, int row){
    return 2*(row*_MAXCOL+col);
  }
  int GetOffsetRow(int offset){
    return offset/(2*_MAXCOL);
  }

  int GetOffsetCol(int offset){
    return (offset-(GetOffsetRow(offset))*2*_MAXCOL)/2;
  }
  int C_Size(char *s){
    int i=0;
    while(s[i]!='\0'){
      if(s[i]<32)
        break;
      i++;
    }
    return i;
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
    /* &&Message[i]>=32&&Message[i]<=127 */
    while(Message[i]!=0){
      CC=GetOffsetCol(GetCursorOffset());
      CR=GetOffsetRow(GetCursorOffset());
      printc(Message[i]);
      i++;

      row=CC;
      col=CR;
    }
    return offset;
  }

  void printo(const char *message,...){
    va_list ap;
    va_start(ap,message);
    vprinto(message,ap);
    va_end(ap);
  }

  void vprinto(const char *message,va_list ap){
    int pointer=0;

    char *str;
    int decimal=0;
    char c;

    while(message[pointer]!='\0'){
      if(message[pointer]=='%'){
        pointer++;
        switch(message[pointer]){
            case 's':
              pointer++;
              str=va_arg(ap,char *);
              if(str[0]!='\0'){
                printo(str);
              }
              break;
            case 'd':
              pointer++;
              decimal=va_arg(ap,int);
              printnum(decimal);
              break;
            case 'c':
              pointer++;
              c=va_arg(ap,int);
              printc(c);
              break;
	    case 'k':
	      pointer++;
	      decimal=va_arg(ap,int);
	      Set_Color(decimal);
	      break;
	    case 'b':
	      pointer++;
	      decimal=va_arg(ap,int);
	      if(decimal==false){
	      	printo("false");
	      }
	      else if(decimal==true){
              	printo("true");
	      }
	      else{
		      printo("UNKNOWN");
	      }
	      break;
            default:
              pointer=pointer-1;
              printc(message[pointer]);
              pointer++;
              break;
          }
      }
      else{
        putchar(message[pointer],GetOffsetCol(GetCursorOffset()),GetOffsetRow(GetCursorOffset()),Get_Color());
        pointer++;
      }
    }
  }

  void Set_Color(int colorx){
	  Current_Color=colorx;
  }

  int Get_Color(){
	  return Current_Color;
  }

  void printnum(int num){
    char *ret=itoa(num);
    printo("%s",ret);
  }

  void SetCursorPosition(int col,int row){
    CR_PRINTO(" ",col,row);
    Backspace();
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
