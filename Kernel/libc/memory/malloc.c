#include <memory.h>
#include <stdio.h>

void initialize(){
  /*
  Free_List->size=20000-sizeof(struct Malloc_Block);
  Free_List->free=1;
  Free_List->next=NULL;*/
  
  printf("Coming soon\n");
  //This function may not be needed...
}

void split(struct Malloc_Block *Fitting_Slot_Size,size_t size){
  /*struct Malloc_Block *new=(void*)((void*)Fitting_Slot_Size+size+sizeof(struct Malloc_Block));
  new->size=(Fitting_Slot_Size->size)-size-sizeof(struct Malloc_Block);
  new->free=1;
  new->next=Fitting_Slot_Size->next;
  Fitting_Slot_Size->size=size;
  Fitting_Slot_Size->free=0;
  Fitting_Slot_Size->next=new;*/
  printf("Coming soon\n");
}

void *malloc(int Bytes)
{
/* malloc Allocates memory (obviously) */

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

void merge(){
  /*struct Malloc_Block *curr,*prev;
  curr=Free_List;
  while((curr->next)!=NULL){
    if((curr->free)&&(curr->next->free)){
      curr->size+=(curr->next->size)+sizeof(struct Malloc_Block);
      curr->next=curr->next->next;
    }
    prev=curr;
    curr=curr->next;
  }*/
  
  printf("Coming soon\n");
}

void free(void* ptr){
  /*if(((void*)mem<=ptr)&&(ptr<=(void*)(mem+20000))){
   struct Malloc_Block* curr=ptr;
   --curr;
   curr->free=1;
   merge();
  }
  else
    printo("Invaild pointer\n");*/
  
  printf("Coming soon\n");
}
