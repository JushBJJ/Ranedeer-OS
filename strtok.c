/* Known Issues:
    None.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

/* For myMalloc */
static char Block[15];
#define mymalloc MyMalloc

/* Debug purposes */
#define debugr printf

/* Basic bool */
#define bool int
#define true 1
#define false 0

/* OLD_NEW */
#define new 1
#define old 0

/* Types */
#define MALOC_INT 1
#define MALLOC_CHAR 2
#define MALLOC_CHAR_POINTER 3

/* Staic Variables, in Ranedeer this will be in a header (string.h or stdio.h) */
static int pointer = 0; //Pointer used for OG_String, it will get reset back to 0 when OLD_NEW is equal to 1
static char *OG_String; //Static just in case, but will get reset when OLD_NEW is equal to 1

// Declare the functions
char *mySTRTOK_NEW(char *Original_String, const char Split_C);
char *mySTRTOK_OLD(char *Original_String, const char Split_C);
void m_strcpy(char *x, char *y);
void *MyMalloc(int Bytes);

/* m_strcpy (Used when memory was already alocated) */
void m_strcpy(char *x, char *y)
{
    strcpy(x, y);
    for (int i = 0;; i++)
    {
        if (x[i] == 0x13)
        {
            i--;
            x[i] = 0x01;
            break;
        }
        if (x[i] == 0x00)
        {
            x[i] = 0x01;
        }
    }
    // Intelletual 100, hardest code ever written
    return;
}

/* MyMalloc */
void *MyMalloc(int Bytes)
{
    /* MyMalloc Allocates memory (obviously) */

    /* Variables */
    int i = 1; // Other letters other than 'i' is mad lol
    int x = 1; // x has joined the battle
    unsigned int Memory_Address = 0x0;

    /* Initialize */
    Block[0 + sizeof(Block)] = 0x03; // This indicates the end of the memory block
    Block[0] = 0x02;                 // This indicates the start of the memory block;

    /* Main */
    // Look for memory
    for (; Block[x] != 0x03; x++) // Loop through the memory block and check for any 0x00's
        if (Block[x] == 0x00)     // If found free memory, get the fuck out of the loop and put the memory into slavery
            break;

    for (i = x; i < Bytes && Block[i] != 0x03 && Block[i] != '\r'; i++)
    //While 'i' [var int] is less than the bytes requested, Block[i] is not at the end of its block, and block[i] is not in the return thing idk...
    {
        Block[i] = 0x01; // This indicates where things are occupied
    }

    // Check if it's the and of the block first
    if (Block[i] == 0x03)
    {
        printf("Out of memory.\n");
        asm("hlt"); // Stop the shit right now
    }

    /* Increment and add 0x13 to indicate the end */
    i++; 
    Block[i] = 0x13;
    return &Block[x];

}

/* strtok_new */
    char *mySTRTOK_NEW(char *Original_String, const char Split_C)
    {
        // This is used for new strings, the use of these arguments (Original_String and Split_C) is told in mySTRTOK()
        // This returns RET (char *RET)

        if (Original_String == NULL) // If Original_String is equal to NULL then thanos snap the user and return what the string used to be.
        {
            char *RET = mySTRTOK_OLD(OG_String, Split_C);
            return RET;
        }
        else
        {
            /* Reset the static variables */
            pointer = 0;
            OG_String = Original_String;

            /* 
            Ok, so basically, strtok_old is a old wise 
            function that does the main job, strtok is 
            the system, this one is also a mini system
        */
            return mySTRTOK_OLD(Original_String, Split_C);
        }
    }

    /* strtok_old */
    char *mySTRTOK_OLD(char *Original_String, const char Split_C)
    {
        // This is used for new strings, the use of these arguments (Original_String and Split_C) is told in mySTRTOK()
        // This returns RET (char *RET)
        if (Original_String == NULL)
        {
            /* Important variables */
            char *RET = (char *)mymalloc(1000); // RET is equal to NULL just in case SUB[pointer] is already at Split_C
            char *SUB = (char *)mymalloc(1000); /// Substitute variable
            int i = 0;
            m_strcpy(SUB, OG_String); // Copy OG_String (static char *OG_String) into the SUB variable
            if (SUB[pointer] == Split_C)
                pointer++;

            while (SUB[pointer] != Split_C) // While SUB pointer char is not equal to SPLIT_C...
            {
                /* Life Saviour: */
                if (SUB[pointer] == '\0')
                {
                    return NULL; // But this can be changed in the future, but now, it's not a problem I guess...
                }
                /* Copy the signular char's into RET's pointer char, then update the 'i' and 'pointer' variable */
                RET[i] = SUB[pointer];
                i++;
                pointer++;
            }
            RET[i] = '\0';
            return RET;
        }
        else
        {
            /* Important variables */
            char *RET = (char *)mymalloc(1000); // RET is equal to NULL just in case SUB[pointer] is already at Split_C
            char *SUB = (char *)mymalloc(1000);
            int i = 0;

            m_strcpy(SUB, Original_String); // Copy OG_String (static char *OG_String) into the SUB variable
            if (SUB[pointer] == Split_C)
                pointer++;
            while (SUB[pointer] != Split_C) // While SUB pointer char is not equal to SPLIT_C...
            {
                /* Copy the signular char's into RET's pointer char, then update the 'i' and 'pointer' variable */
                RET[i] = SUB[pointer];
                /* Life Saviour: */
                if (SUB[pointer] == '\0')
                {
                    RET[i] = '\0';
                    return RET; // But this can be changed in the future, but now, it's not a problem I guess...
                }

                /* Update the variables (i) and (pointer) [type = int] */
                i++;
                pointer++;
            }
            RET[i] = '\0'; // Put 0x00 at the end of the string for safety of course
            return RET;
        }
    }

    /* Strtok */
    char *mySTRTOK(char *Original_String, const char Split_C, bool OLD_NEW)
    {
        // Use of these arguments:
        //  Original_Text is used to be copied into a substitued and into a return char so the variable wont get modified
        //  Split_Char is used as a flag on where to split the char
        //  OLD_NEW is a boolean that indicates whether a new pointer should be use or not (1 means new, 0 means old)

        // Variables
        char *RET = (char *)mymalloc(1000);

        //Conditions
        if (OLD_NEW == new &&Original_String == NULL) //If OLD_NEW variable is set to new and Original_String is NULL then...
        {
            // Why, why would I do this but anyway, its a bug fixer
            printf("Error, you cannot have NULL as the Original_String [Var] and OLD_NEW [Var] as new (1) at the same time!\n");
            return NULL;
        }
        else if (OLD_NEW == new) // If OLD_NEW bool is equal to NEW then....
        {
            strcpy(RET, mySTRTOK_NEW(Original_String, Split_C));
            return RET;
        }
        else if (OLD_NEW == old) // If OLD_NEW bool is equal to OLD then...
        {
            // Checking if OG_String is NULL or not..else, it strtok will go through the normal procedure
            if (OG_String == NULL)
            {
                printf("OG_String [Var] is NULL.\n");
                return NULL;
            }
            strcpy(RET, mySTRTOK_OLD(OG_String, Split_C));
            return RET;
        }
        else //If some retard, probably me incorrectly used bool then fuck me mate.
        {
            printf("Unknown bool.\n");
            return NULL;
        }
    }

    int main()
    {
        /* Main vars */
        /*char *asd = "Hello World";
    char *ret = mySTRTOK("ECHO HELLO", ' ', new); // test strtok

    printf("strtok: %s\n", ret);

    ret = mySTRTOK("ECHO HELLO", ' ', old);

    printf("strtok: %s\n", ret);*/
        int i = 0;
        char *x = (char *)mymalloc(12);
        m_strcpy(x, "a");

        m_printf("x address: %p\nBlock[0] address: %p\nx: %s\n", &x[0], &Block[0], x);

        for (int i = 0; Block[i] != 0x03; i++)
        {
            printf("Block[%d]: %x\n", i, Block[i]);
        }

        return 0;
    }