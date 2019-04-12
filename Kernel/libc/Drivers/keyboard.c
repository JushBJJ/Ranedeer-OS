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
        Key[0] = 0x02;
        break;

    // 2
    case 0x3:
        Key[0] = 0x03;
        break;

    // 3
    case 0x4:
        Key[0] = 0x04;
        break;

    // 4
    case 0x5:
        Key[0] = 0x05;
        break;

        // 5
    case 0x6:
        Key[0] = 0x06;
        break;

    // 6
    case 0x7:
        Key[0] = 0x07;
        break;

    // 7
    case 0x8:
        Key[0] = 0x08;
        break;

    // 8
    case 0x9:
        Key[0] = 0x09;
        break;

    // 9
    case 0x0A:
        Key[0] = 0x0A;
        break;

    // 0
    case 0x0B:
        Key[0] = 0x0B;
        break;

    // -
    case 0x0C:
        Key[0] = 0x0C;
        break;

    // +
    case 0x0D:
        Key[0] = 0x0D;
        break;

    // backspace
    case 0x0E:
        Key[0] = 0x0E;
        break;

    // Tab
    case 0x0F:
        Key[0] = 0x0F;
        break;

    // Q
    case 0x10:
        Key[0] = 0x10;
        break;

    // W
    case 0x11:
        Key[0] = 0x11;
        break;

    // E
    case 0x12:
        Key[0] = 0x12;
        break;

    // R
    case 0x13:
        Key[0] = 0x13;
        break;

    // T
    case 0x14:
        Key[0] = 0x14;
        break;

    // Y
    case 0x15:
        Key[0] = 0x15;
        break;

    // U
    case 0x16:
        Key[0] = 0x16;
        break;

    // I
    case 0x17:
        Key[0] = 0x17;
        break;

    // O
    case 0x18:
        Key[0] = 0x18;
        break;

    // P
    case 0x19:
        Key[0] = 0x19;
        break;

    // [
    case 0x1A:
        Key[0] = 0x1A;
        break;

    // ]
    case 0x1B:
        Key[0] = 0x1B;
        break;

    // Enter
    case 0x1C:
        Key[0] = 0x1C;
        break;

    // Left Ctrl
    case 0x1D:
        Key[0] = 0x1D;
        break;

    // A
    case 0x1E:
        Key[0] = 0x1E;
        break;

    // S
    case 0x1F:
        Key[0] = 0x1F;
        break;

    // D
    case 0x20:
        Key[0] = 0x20;
        break;

    // F
    case 0x21:
        Key[0] = 0x21;
        break;

    // G
    case 0x22:
        Key[0] = 0x22;
        break;

    // H
    case 0x23:
        Key[0] = 0x23;
        break;

    // J
    case 0x24:
        Key[0] = 0x24;
        break;

    // K
    case 0x25:
        Key[0] = 0x25;
        break;

    // L
    case 0x26:
        Key[0] = 0x26;
        break;

    // ;
    case 0x27:
        Key[0] = 0x27;
        break;

    // '
    case 0x28:
        Key[0] = 0x28;
        break;

    // `
    case 0x29:
        Key[0] = 0x29;
        break;

    // Left Shift
    case 0x2A:
        Key[0] = 0x2A;
        break;

        // \ 
  case 0x2B:
        Key[0] = 0x2B;
        break;

    // Z
    case 0x2C:
        Key[0] = 0x2C;
        break;

    // X
    case 0x2D:
        Key[0] = 0x2D;
        break;

    // C
    case 0x2E:
        Key[0] = 0x2E;
        break;

    //V
    case 0x2F:
        Key[0] = 0x2F;
        break;

    // B
    case 0x30:
        Key[0] = 0x30;
        break;

    // N
    case 0x31:
        Key[0] = 0x31;
        break;

    //M
    case 0x32:
        Key[0] = 0x32;
        break;

    // ,
    case 0x33:
        Key[0] = 0x33;
        break;

    // .
    case 0x34:
        Key[0] = 0x34;
        break;

    // /
    case 0x35:
        Key[0] = 0x35;
        break;

    // Right Shift
    case 0x36:
        Key[0] = 0x36;
        break;

    // *
    case 0x37:
        Key[0] = 0x37;
        break;

    // Left Alt
    case 0x38:
        Key[0] = 0x38;
        break;

    // Space
    case 0x39:
        Key[0] = 0x39;
        break;

    // Unknown
    default:
        break;
    }
}
