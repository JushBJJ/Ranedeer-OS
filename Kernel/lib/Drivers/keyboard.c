#include <Drivers/keyboard.h>
#include <CPU/ports.h>
#include <CPU/isr.h>
#include <Drivers/screen.h>
#include <io/Data.h>
#include <String/utils.h>
#include <Kernel.h>
#include <io/Ranedeerio.h>
#include <Signal/signal.h>

static int BARRIER;

void KeyboardOut(u8 scancode);

static char KeyBuffer[256];
static char RetKB[256];

void DisableKeyboard(){
  asm("cli");
}

void SetCursorBarrier(int offset){
  BARRIER=offset;
}
void EnableKeyboard(){
  KE=1;
  asm("sti");
}

void DisableInput(){
  InputEnabled=0;
}

void EnableInput(){
  InputEnabled=1;
}

static void KeyboardCallback(registersT regs){
  u8 scancode=PBI(0x60);
  KeyboardOut(scancode);

  unused(regs);
}

void initKeyboard(){
  RegisterInterruptHandler(IRQ1,KeyboardCallback);
}
void KeyboardOut(u8 scancode){
  switch(scancode){
  case 0x0:
    printo("ERROR");
  break;
  case 0x1:
    /*esc*/
  break;
  case 0x2:
    printo("1");
    AddtoChar(KeyBuffer,'1');
  break;
  case 0x3:
    printo("2");
    AddtoChar(KeyBuffer,'2');
  break;
  case 0x4:
    printo("3");
    AddtoChar(KeyBuffer,'3');
  break;
  case 0x5:
    printo("4");
    AddtoChar(KeyBuffer,'4');
  break;
  case 0x6:
    printo("5");
    AddtoChar(KeyBuffer,'5');
  break;
  case 0x7:
    printo("6");
    AddtoChar(KeyBuffer,'6');
  break;
  case 0x8:
    printo("7");
    AddtoChar(KeyBuffer,'7');
  break;
  case 0x9:
    printo("8");
    AddtoChar(KeyBuffer,'8');
  break;
  case 0x0A:
    printo("9");
    AddtoChar(KeyBuffer,'9');
  break;
  case 0x0B:
    printo("0");
    AddtoChar(KeyBuffer,'0');
  break;
  case 0x0C:
    printo("-");
    AddtoChar(KeyBuffer,'-');
  break;
  case 0x0D:
    printo("+");
    AddtoChar(KeyBuffer,'+');
  break;
  case 0x0E:
    if(GetCursorOffset()!=BARRIER){
      Backspace();
      BackspaceChar(KeyBuffer);
    }
  break;
  case 0x0F:
    printo("    ");
    AddtoChar(KeyBuffer,' ');
    AddtoChar(KeyBuffer,' ');
    AddtoChar(KeyBuffer,' ');
    AddtoChar(KeyBuffer,' ');
  break;
  case 0x10:
    printo("Q");
    AddtoChar(KeyBuffer,'Q');
  break;
  case 0x11:
    printo("W");
    AddtoChar(KeyBuffer,'W');
  break;
  case 0x12:
    printo("E");
    AddtoChar(KeyBuffer,'E');
  break;
  case 0x13:
    printo("R");
    AddtoChar(KeyBuffer,'R');
  break;
  case 0x14:
    printo("T");
    AddtoChar(KeyBuffer,'T');
  break;
  case 0x15:
    printo("Y");
    AddtoChar(KeyBuffer,'Y');
  break;
  case 0x16:
    printo("U");
    AddtoChar(KeyBuffer,'U');
  break;
  case 0x17:
    printo("I");
    AddtoChar(KeyBuffer,'I');
  break;
  case 0x18:
    printo("O");
    AddtoChar(KeyBuffer,'O');
  break;
  case 0x19:
    printo("P");
    AddtoChar(KeyBuffer,'P');
  break;
  case 0x1A:
    printo("[");
    AddtoChar(KeyBuffer,'[');
  break;
  case 0x1B:
    printo("]");
    AddtoChar(KeyBuffer,']');
  break;
  case 0x1C:
    printo("\n");
    if(InputEnabled==1){
      RetKB[0]='\0';
      for(int i=0;KeyBuffer[i]!='\0';i++){
        RetKB[i]=KeyBuffer[i];
      }
      SendSignal(SIG_INPUT);
      SetToChar(RetKB);
      int x=strlen(RetKB);
      for(int i=0;i<x;i++){
        RetKB[i]='\0';
        KeyBuffer[i]='\0';
      }
    }
  break;
  case 0x1D:
    /*Left Ctrl*/
  break;
  case 0x1E:
    printo("A");
    AddtoChar(KeyBuffer,'A');
  break;
  case 0x1F:
    printo("S");
    AddtoChar(KeyBuffer,'S');
  break;
  case 0x20:
    printo("D");
    AddtoChar(KeyBuffer,'D');
  break;
  case 0x21:
    printo("F");
    AddtoChar(KeyBuffer,'F');
  break;
  case 0x22:
    printo("G");
    AddtoChar(KeyBuffer,'G');
  break;
  case 0x23:
    printo("H");
    AddtoChar(KeyBuffer,'H');
  break;
  case 0x24:
    printo("J");
    AddtoChar(KeyBuffer,'J');
  break;
  case 0x25:
    printo("K");
    AddtoChar(KeyBuffer,'K');
  break;
  case 0x26:
    printo("L");
    AddtoChar(KeyBuffer,'L');
  break;
  case 0x27:
    printo(";");
    AddtoChar(KeyBuffer,';');
  break;
  case 0x28:
    printo("'");
    AddtoChar(KeyBuffer,'\'');
  break;
  case 0x29:
    printo("`");
    AddtoChar(KeyBuffer,'\'');
  break;
  case 0x2A:
    /*Left Shift*/
  break;
  case 0x2B:
    printo("\\");
    AddtoChar(KeyBuffer,'\\');
  break;
  case 0x2C:
    printo("Z");
    AddtoChar(KeyBuffer,'Z');
  break;
  case 0x2D:
    printo("X");
    AddtoChar(KeyBuffer,'X');
  break;
  case 0x2E:
    printo("C");
    AddtoChar(KeyBuffer,'C');
  break;
  case 0x2F:
    printo("V");
    AddtoChar(KeyBuffer,'V');
  break;
  case 0x30:
    printo("B");
    AddtoChar(KeyBuffer,'B');
  break;
  case 0x31:
    printo("N");
    AddtoChar(KeyBuffer,'N');
  break;
  case 0x32:
    printo("M");
    AddtoChar(KeyBuffer,'M');
  break;
  case 0x33:
    printo(",");
    AddtoChar(KeyBuffer,',');
  break;
  case 0x34:
    printo(".");
    AddtoChar(KeyBuffer,'.');
  break;
  case 0x35:
    printo("/");
    AddtoChar(KeyBuffer,'/');
  break;
  case 0x36:
    /*Right shift*/
  break;
  case 0x37:
    printo("*");
    AddtoChar(KeyBuffer,'*');
  break;
  case 0x38:
    /*left alt*/
  break;
  case 0x39:
    printo(" ");
    AddtoChar(KeyBuffer,' ');
  break;

  default:
    break;
}
}
