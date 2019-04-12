#include <__IN__.h>
#include <isr.h>
#include <keyboard.h>
#include <stdio.h>

char *KeyList[] =
    {
        "ERROR", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
                                                                     "-",
        "+", "BACKSPACE",
        "   ", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\n",
        "LEFT_CTRL", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", "LEFT SHIFT", "\\",
        "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "RIGHT_SHIFT", "*", "LEFT_ALT", " "}

char KeyList_Code[] =
    {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39}

void
_input()
{
    IN->__INPUT_DONE = true;
}

char *input()
{
    /* 0x1C is basically the Enter key */
    while (Key[0] != 0x1C)
    {
        int i = 0;
        for (; KeyList_Code[i] != Key[0] && i < sizeof(KeyList_Code); i++)
        {
        }

        // Dude this awful fucking code
        if (
            Key[0] != 0x00 && // ERROR
            Key[0] != 0x01 && // ESC
            Key[0] != 0x0E && // Backspace
            Key[0] != 0x0F && // TAB
            Key[0] != 0x2A && // Left shift
            Key[0] != 0x36 && // Right Shift
            Key[0] != 0x38 && // Left ALt
            )                 // Only do this operation if Key[0] is not NULL
        {
            if (KeyList_Code[i] == Key[0]) //If Key[0] is equal to one of that Key codes that represent a char or string
            {
                Input_Block[Input_Block_Pointer] = Key_List[i]; // Update the Input_Block and put that char into the thing
                Key[0] = 0x00;
            }
            if (Keyboard_Switch == true)
            {
                printc(Input_Block[Input_Block_Pointer]);
            }

            Input_Block_Pointer++;
        }
    }
    printf("\n");
    return Input_Block;
}
