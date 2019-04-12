#include <keyboard.h>
#include <stdio.h>
#include <Data.h>
#include <ports.h>
#include <__IN__.h>
#include <Shell.h>

void KeyboardOut(u8 scancode);

void EnableKeyboard()
{
    EnableInterrupts();
}

void DisableKeyboard()
{
    DisableInterrupts();
}

void SetCursorBarrier(int offset)
{
    IN->BARRIER = offset;
}

void SetCursorBarrierHere()
{
    IN->BARRIER = GetCursorOffset();
}

void DisableCursorBarrier()
{
    IN->BARRIER = -1;
}

void DisableInput()
{
    InputEnabled = 0;
}

void EnableInput()
{
    InputEnabled = 1;
}

static void KeyboardCallback(registersT regs)
{
    u8 scancode = PBI(0x60);
    KeyboardOut(scancode);
    unused(regs);
}

void initKeyboard()
{
    RegisterInterruptHandler(IRQ1, KeyboardCallback);
}

void KeyboardOut(u8 scancode)
{
    switch (scancode)
    {
    // Unknown
    case 0x0:
        printo("ERROR");
        asm("hlt");
        break;

    // Escape Key (esc)
    case 0x1:
        /*esc*/
        break;

    // 1
    case 0x2:
        Key[0] = 0x0000D1;
        break;

    // 2
    case 0x3:
        Key[0] = 0x0000D2;
        break;

    // 3
    case 0x4:
        Key[0] = 0x0000D3;
        break;

    // 4
    case 0x5:
        Key[0] = 0x0000D4;
        break;

        // 5
    case 0x6:
        Key[0] = 0x0000D5;
        break;

    // 6
    case 0x7:
        Key[0] = 0x0000D6;
        break;

    // 7
    case 0x8:
        Key[0] = 0x0000D7;
        break;

    // 8
    case 0x9:
        Key[0] = 0x0000D8;
        break;

    // 9
    case 0x0A:
        Key[0] = 0x0000D9;
        break;

    // 0
    case 0x0B:
        Key[0] = 0x0000DA;
        break;

    // -
    case 0x0C:
        Key[0] = 0x0000DB;
        break;

    // +
    case 0x0D:
        Key[0] = 0x0000DC;
        break;

    // backspace
    case 0x0E:
        Key[0] = 0x0000DD;
        break;

    // Tab
    case 0x0F:
        Key[0] = 0x0000DE;
        break;

    // Q
    case 0x10:
        Key[0] = 0x0000DF;
        break;

    // W
    case 0x11:
        Key[0] = 0x0000DF1;
        break;

    // E
    case 0x12:
        Key[0] = 0x0000DF2;
        break;

    // R
    case 0x13:
        Key[0] = 0x0000DF3;
        break;

    // T
    case 0x14:
        Key[0] = 0x0000DF4;
        break;

    // Y
    case 0x15:
        Key[0] = 0x0000DF5;
        break;

    // U
    case 0x16:
        Key[0] = 0x0000DF6;
        break;

    // I
    case 0x17:
        Key[0] = 0x0000DF7;
        break;

    // O
    case 0x18:
        Key[0] = 0x0000DF8;
        break;

    // P
    case 0x19:
        Key[0] = 0x0000DF9;
        break;

    // [
    case 0x1A:
        Key[0] = 0x0000DFA;
        break;

    // ]
    case 0x1B:
        Key[0] = 0x0000DFB;
        break;

    // Enter
    case 0x1C:
        Key[0] = 0x0000DFC;
        break;

    // Left Ctrl
    case 0x1D:
        Key[0] = 0x0000DFD;
        break;

    // A
    case 0x1E:
        Key[0] = 0x0000DFE;
        break;

    // S
    case 0x1F:
        Key[0] = 0x0000DFF;
        break;

    // D
    case 0x20:
        Key[0] = 0x0000DE1;
        break;

    // F
    case 0x21:
        Key[0] = 0x0000DE2;
        break;

    // G
    case 0x22:
        Key[0] = 0x0000DE3;
        break;

    // H
    case 0x23:
        Key[0] = 0x0000DE4;
        break;

    // J
    case 0x24:
        Key[0] = 0x0000DE5;
        break;

    // K
    case 0x25:
        Key[0] = 0x0000DE5;
        break;

    // L
    case 0x26:
        Key[0] = 0x0000DE6;
        break;

    // ;
    case 0x27:
        Key[0] = 0x0000DE7;
        break;

    // '
    case 0x28:
        Key[0] = 0x0000DE8;
        break;

    // `
    case 0x29:
        Key[0] = 0x0000DE9;
        break;

    // Left Shift
    case 0x2A:
        Key[0] = 0x0000DEA;
        break;

        // \ 
  case 0x2B:
        Key[0] = 0x0000DEB;
        break;

    // Z
    case 0x2C:
        Key[0] = 0x0000DEC;
        break;

    // X
    case 0x2D:
        Key[0] = 0x0000DED;
        break;

    // C
    case 0x2E:
        Key[0] = 0x0000DEE;
        break;

    //V
    case 0x2F:
        Key[0] = 0x0000DEF;
        break;

    // B
    case 0x30:
        Key[0] = 0x0000DD1;
        break;

    // N
    case 0x31:
        Key[0] = 0x0000DD2;
        break;

    //M
    case 0x32:
        Key[0] = 0x0000DD3;
        break;

    // ,
    case 0x33:
        Key[0] = 0x0000DD4;
        break;

    // .
    case 0x34:
        Key[0] = 0x0000DD5;
        break;

    // /
    case 0x35:
        Key[0] = 0x0000DD6;
        break;

    // Right Shift
    case 0x36:
        Key[0] = 0x0000DD7;
        break;

    // *
    case 0x37:
        Key[0] = 0x0000DD8;
        break;

    // Left Alt
    case 0x38:
        Key[0] = 0x0000DD9;
        break;

    // Space
    case 0x39:
        Key[0] = 0x0000DDA;
        break;

    // Unknown
    default:
        break;
    }
}
