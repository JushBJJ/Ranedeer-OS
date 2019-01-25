#include <memory.h>
#include <stdio.h>

void initialize(){
  Free_List->size=1024*1024-sizeof(struct Malloc_Block);
  Free_List->free=1;
  Free_List->next=NULL;
}

void split(struct Malloc_Block *Fitting_Slot_Size,size_t size){
  struct Malloc_Block *new=(void*)((void*)Fitting_Slot_Size+size+sizeof(struct Malloc_Block));
  new->size=(Fitting_Slot_Size->size)-size-sizeof(struct Malloc_Block);
  new->free=1;
  new->next=Fitting_Slot_Size->next;
  Fitting_Slot_Size->size=size;
  Fitting_Slot_Size->free=0;
  Fitting_Slot_Size->next=new;

}

void merge(){
  struct Malloc_Block *curr,*prev;
  curr=Free_List;
  while((curr->next)!=NULL){
    if((curr->free)&&(curr->next->free)){
      curr->size+=(curr->next->size)+sizeof(struct Malloc_Block);
      curr->next=curr->next->next;
    }
  }
  prev=curr;
  curr=curr->next;
}

void free(void *ptr){
  if(((void*)mem<=ptr)&&(ptr<=(void*)(mem+20000))){
    struct Malloc_Block* curr=ptr;
    curr=curr-1;
    curr->free=1;
    merge();
  }
  else{
    printo("Invaild pointer\n");
  }
}

void *malloc(size_t size)
{
    struct Malloc_Block *curr,*prev;
    void *result;
    if(!(Free_List->size)){
      initialize();
    }
    curr=Free_List;
     while((((curr->size)<size)||((curr->free)==0))&&(curr->next!=NULL)){
       prev=curr;
       curr=curr->next;
     }
     if((curr->size)==size){
       curr->free=0;
       result=(void*)(++curr);
       return result;
     }
     else if((curr->size)>(size+sizeof(struct Malloc_Block))){
       split(curr,size);
       result=(void*)(curr++);
       return result;
     }
     else{
       result=NULL;
       printo("Unable to allocate memory\n");
       return result;
     }
}
