#include <keyboard.h>
#include <stdio.h>
#include <Data.h>
#include <ports.h>
#include <__IN__.h>
#include <Shell.h>

void KeyboardOut(u8 scancode);

void EnableKeyboard(){
  EnableInterrupts();
}

void DisableKeyboard(){
  DisableInterrupts();
}

void SetCursorBarrier(int offset){
  IN->BARRIER=offset;
}

void SetCursorBarrierHere(){
  IN->BARRIER=GetCursorOffset();
}

void DisableCursorBarrier(){
  IN->BARRIER=-1;
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
    AddtoChar('1');
  break;
  case 0x3:
    printo("2");
    AddtoChar('2');
  break;
  case 0x4:
    printo("3");
    AddtoChar('3');
  break;
  case 0x5:
    printo("4");
    AddtoChar('4');
  break;
  case 0x6:
    printo("5");
    AddtoChar('5');
  break;
  case 0x7:
    printo("6");
    AddtoChar('6');
  break;
  case 0x8:
    printo("7");
    AddtoChar('7');
  break;
  case 0x9:
    printo("8");
    AddtoChar('8');
  break;
  case 0x0A:
    printo("9");
    AddtoChar('9');
  break;
  case 0x0B:
    printo("0");
    AddtoChar('0');
  break;
  case 0x0C:
    printo("-");
    AddtoChar('-');
  break;
  case 0x0D:
    printo("+");
    AddtoChar('+');
  break;
  case 0x0E:
    if(GetCursorOffset()!=IN->BARRIER){
      Backspace();
    }
    BackspaceChar();
  break;
  case 0x0F:
    printo("    ");
    AddtoChar(' ');
    AddtoChar(' ');
    AddtoChar(' ');
    AddtoChar(' ');
  break;
  case 0x10:
    printo("Q");
    AddtoChar('Q');
  break;
  case 0x11:
    printo("W");
    AddtoChar('W');
  break;
  case 0x12:
    printo("E");
    AddtoChar('E');
  break;
  case 0x13:
    printo("R");
    AddtoChar('R');
  break;
  case 0x14:
    printo("T");
    AddtoChar('T');
  break;
  case 0x15:
    printo("Y");
    AddtoChar('Y');
  break;
  case 0x16:
    printo("U");
    AddtoChar('U');
  break;
  case 0x17:
    printo("I");
    AddtoChar('I');
  break;
  case 0x18:
    printo("O");
    AddtoChar('O');
  break;
  case 0x19:
    printo("P");
    AddtoChar('P');
  break;
  case 0x1A:
    printo("[");
    AddtoChar('[');
  break;
  case 0x1B:
    printo("]");
    AddtoChar(']');
  break;
  case 0x1C:
    printo("\n");
    AddtoChar('\n');
    break;
  case 0x1D:
    /*Left Ctrl*/
  break;
  case 0x1E:
    printo("A");
    AddtoChar('A');
  break;
  case 0x1F:
    printo("S");
    AddtoChar('S');
  break;
  case 0x20:
    printo("D");
    AddtoChar('D');
  break;
  case 0x21:
    printo("F");
    AddtoChar('F');
  break;
  case 0x22:
    printo("G");
    AddtoChar('G');
  break;
  case 0x23:
    printo("H");
    AddtoChar('H');
  break;
  case 0x24:
    printo("J");
    AddtoChar('J');
  break;
  case 0x25:
    printo("K");
    AddtoChar('K');
  break;
  case 0x26:
    printo("L");
    AddtoChar('L');
  break;
  case 0x27:
    printo(";");
    AddtoChar(';');
  break;
  case 0x28:
    printo("'");
    AddtoChar('\'');
  break;
  case 0x29:
    printo("`");
    AddtoChar('\'');
  break;
  case 0x2A:
    /*Left Shift*/
  break;
  case 0x2B:
    printo("\\");
    AddtoChar('\\');
  break;
  case 0x2C:
    printo("Z");
    AddtoChar('Z');
  break;
  case 0x2D:
    printo("X");
    AddtoChar('X');
  break;
  case 0x2E:
    printo("C");
    AddtoChar('C');
  break;
  case 0x2F:
    printo("V");
    AddtoChar('V');
  break;
  case 0x30:
    printo("B");
    AddtoChar('B');
  break;
  case 0x31:
    printo("N");
    AddtoChar('N');
  break;
  case 0x32:
    printo("M");
    AddtoChar('M');
  break;
  case 0x33:
    printo(",");
    AddtoChar(',');
  break;
  case 0x34:
    printo(".");
    AddtoChar('.');
  break;
  case 0x35:
    printo("/");
    AddtoChar('/');
  break;
  case 0x36:
    /*Right shift*/
  break;
  case 0x37:
    printo("*");
    AddtoChar('*');
  break;
  case 0x38:
    /*left alt*/
  break;
  case 0x39:
    printo(" ");
    AddtoChar(' ');
  break;

  default:
    break;
}
}
