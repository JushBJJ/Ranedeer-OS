#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <string.h>

/* strtok_new */
    char *strtok_new(char *Original_String, const char Split_C)
    {
        // This is used for new strings, the use of these arguments (Original_String and Split_C) is told in mySTRTOK()
        // This returns RET (char *RET)

        if (Original_String == NULL) // If Original_String is equal to NULL then thanos snap the user and return what the string used to be.
        {
            char *RET = strtok_old(OG_String, Split_C);
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
            return strtok_old(Original_String, Split_C);
        }
    }

    /* strtok_old */
    char *strtok_old(char *Original_String, const char Split_C)
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
            char *RET = (char *)malloc(1000); // RET is equal to NULL just in case SUB[pointer] is already at Split_C
            char *SUB = (char *)malloc(1000);
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
    char *strtok(char *Original_String, const char Split_C, bool OLD_NEW)
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
            strcpy(RET, strtok_new(Original_String, Split_C));
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
            strcpy(RET, strtok_old(OG_String, Split_C));
            return RET;
        }
        else //If some retard, probably me incorrectly used bool then fuck me mate.
        {
            printf("Unknown bool.\n");
            return NULL;
        }
    }

