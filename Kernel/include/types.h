#ifndef TYPES_H
  #define TYPES_H

  typedef unsigned int u32;
  typedef int s32;
  typedef unsigned short u16;
  typedef short s16;
  typedef unsigned char u8;
  typedef char s8;

  #define size_t unsigned int;

  #define low_16(address)(u16)((address)&0xFFFF)
  #define high_16(address)(u16)(((address)>>16)&0xFFFF)

  typedef struct{
    u32 ds; //Data Segment
    u32 edi,esi,ebp,esp,ebx,edx,ecx,eax; //32 bit registers (obviously)
    u32 IntNo,ErrCode;
    u32 eip,cs,eflags,useresp,ss;
  } registersT;


  typedef void (*isrT)(registersT);

#endif
