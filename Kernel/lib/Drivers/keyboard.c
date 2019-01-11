#include <Drivers/keyboard.h>
#include <Drivers/ports.h>
#include <CPU/isr.h>
#include <Drivers/screen.h>
#include <Data.h>
#include <utils.h>

void KeyboardOut(u8 scancode);

static void KeyboardCallback(registersT regs){
  u8 scancode=PBI(0x60);
  char *ScAscii;

  ToAscii(scancode,ScAscii);
  printo("Keyboard Scancode: ");
  printo(ScAscii);
  printo(", ");
  KeyboardOut(scancode);
  printo("\n");
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
  break;
  case 0x3:
    printo("2");
  break;
  case 0x4:
    printo("3");
  break;
  case 0x5:
    printo("4");
  break;
  case 0x6:
    printo("5");
  break;
  case 0x7:
    printo("6");
  break;
  case 0x8:
    printo("7");
  break;
  case 0x9:
    printo("8");
  break;
  case 0x0A:
    printo("9");
  break;
  case 0x0B:
    printo("0");
  break;
  case 0x0C:
    printo("-");
  break;
  case 0x0D:
    printo("+");
  break;
  case 0x0E:
    //Backspace();
  break;
  case 0x0F:
    printo("    ");
  break;
  case 0x10:
    printo("Q");
  break;
  case 0x11:
    printo("W");
  break;
  case 0x12:
    printo("E");
  break;
  case 0x13:
    printo("R");
  break;
  case 0x14:
    printo("T");
  break;
  case 0x15:
    printo("Y");
  break;
  case 0x16:
    printo("U");
  break;
  case 0x17:
    printo("I");
  break;
  case 0x18:
    printo("O");
  break;
  case 0x19:
    printo("P");
  break;
  case 0x1A:
    printo("[");
  break;
  case 0x1B:
    printo("]");
  break;
  case 0x1C:
    printo("\n");
  break;
  case 0x1D:
    /*Left Ctrl*/
  break;
  case 0x1E:
    printo("A");
  break;
  case 0x1F:
    printo("S");
  break;
  case 0x20:
    printo("D");
  break;
  case 0x21:
    printo("F");
  break;
  case 0x22:
    printo("G");
  break;
  case 0x23:
    printo("H");
  break;
  case 0x24:
    printo("J");
  break;
  case 0x25:
    printo("K");
  break;
  case 0x26:
    printo("L");
  break;
  case 0x27:
    printo(";");
  break;
  case 0x28:
    printo("'");
  break;
  case 0x29:
    printo("`");
  break;
  case 0x2A:
    /*Left Shift*/
  break;
  case 0x2B:
    printo("\\");
  break;
  case 0x2C:
    printo("Z");
  break;
  case 0x2D:
    printo("X");
  break;
  case 0x2E:
    printo("C");
  break;
  case 0x2F:
    printo("V");
  break;
  case 0x30:
    printo("B");
  break;
  case 0x31:
    printo("N");
  break;
  case 0x32:
    printo("M");
  break;
  case 0x33:
    printo(",");
  break;
  case 0x34:
    printo(".");
  break;
  case 0x35:
    printo("/");
  break;
  case 0x36:
    /*Right shift*/
  break;
  case 0x37:
    printo("*");
  break;
  case 0x38:
    /*left alt*/
  break;
  case 0x39:
    /*spc*/
  break;

  default:
    break;
}
}
