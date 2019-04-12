#include <string.h>
#include <memory.h>

char *strncpy(char *Origin, char *Copied, size_t SizeOfString){  
  for(size_t i=0; i<SizeOfString+1; i++){
    Origin[i]=Copied[i];
  }
  
  Origin[0+strlen(Origin)]=0x00;
  return Origin;
}

char *strcpy(char *Origin,char *Copied){
  dest = strncpy(Origin, Copied, strlen(Copied);
  return dest;
}
                 
/* m_strcpy (Used when memory was already alocated) */
void m_strcpy(char *x, char *y)
{
    strcpy(x, y); // Copy the shit first
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

