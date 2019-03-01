#include <isr.h>
#include <idt.h>
#include <screen.h>
#include <string.h>
#include <ports.h>
#include <timer.h>
#include <keyboard.h>
#include <stdio.h>
#include <__IN__.h>

isrT InterruptHandlers[256];

void isr_install() {
    SetIdtGate(0,(u32)isr0);
    SetIdtGate(1,(u32)isr1);
    SetIdtGate(2,(u32)isr2);
    SetIdtGate(3,(u32)isr3);
    SetIdtGate(4,(u32)isr4);
    SetIdtGate(5,(u32)isr5);
    SetIdtGate(6,(u32)isr6);
    SetIdtGate(7,(u32)isr7);
    SetIdtGate(8,(u32)isr8);
    SetIdtGate(9,(u32)isr9);
    SetIdtGate(10,(u32)isr10);
    SetIdtGate(11,(u32)isr11);
    SetIdtGate(12,(u32)isr12);
    SetIdtGate(13,(u32)isr13);
    SetIdtGate(14,(u32)isr14);
    SetIdtGate(15,(u32)isr15);
    SetIdtGate(16,(u32)isr16);
    SetIdtGate(17,(u32)isr17);
    SetIdtGate(18,(u32)isr18);
    SetIdtGate(19,(u32)isr19);
    SetIdtGate(20,(u32)isr20);
    SetIdtGate(21,(u32)isr21);
    SetIdtGate(22,(u32)isr22);
    SetIdtGate(23,(u32)isr23);
    SetIdtGate(24,(u32)isr24);
    SetIdtGate(25,(u32)isr25);
    SetIdtGate(26,(u32)isr26);
    SetIdtGate(27,(u32)isr27);
    SetIdtGate(28,(u32)isr28);
    SetIdtGate(29,(u32)isr29);
    SetIdtGate(30,(u32)isr30);
    SetIdtGate(31,(u32)isr31);

    PBO(0x20,0x11);
    PBO(0xA0,0x11);
    PBO(0x21,0x20);
    PBO(0xA1,0x20);
    PBO(0x21,0x04);
    PBO(0xA1,0x02);
    PBO(0x21,0x01);
    PBO(0xA1,0x01);
    PBO(0x21,0x0);
    PBO(0xA1,0x0);

    SetIdtGate(32, (u32)irq0);
    SetIdtGate(33, (u32)irq1);
    SetIdtGate(34, (u32)irq2);
    SetIdtGate(35, (u32)irq3);
    SetIdtGate(36, (u32)irq4);
    SetIdtGate(37, (u32)irq5);
    SetIdtGate(38, (u32)irq6);
    SetIdtGate(39, (u32)irq7);
    SetIdtGate(40, (u32)irq8);
    SetIdtGate(41, (u32)irq9);
    SetIdtGate(42, (u32)irq10);
    SetIdtGate(43, (u32)irq11);
    SetIdtGate(44, (u32)irq12);
    SetIdtGate(45, (u32)irq13);
    SetIdtGate(46, (u32)irq14);
    SetIdtGate(47, (u32)irq15);

    SetIdt();
}

char *ExceptionMessages[]={
  "Division by zero",
  "Debug",
  "Non maskable Interupt",
  "Breakpoint",
  "Info detected overflow",
  "Out of bounds",
  "Invaild opcode",
  "No Coprocessor",
  "Double fault,"
  "Coprocessor Segment Overrun",
  "Bad TSS",
  "Segment Not present",
  "Stack Fault",
  "General Protection Fault",
  "Page Fault",
  "Unknown Interrupt",
  "Coproccessor Fault",
  "Alignment Check",
  "Machine Checked",
  "syscall",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

void IsrHandler(registersT *t){
  printo("Recieved Interrupt: %d\nException Message: %s\n",t->IntNo,ExceptionMessages[t->IntNo]);

  printo("eax: %c\n",t->edi);
}

void RegisterInterruptHandler(u8 n,isrT handler){
  InterruptHandlers[n]=handler;
}

void irqhandler(registersT *t){
  if(t->IntNo>=40){
    PBO(0xA0,0x20);
  }
  PBO(0x20,0x20);

  if(InterruptHandlers[t->IntNo]!=0){
    isrT handler=InterruptHandlers[t->IntNo];
    handler(*t);
  }
}

void EnableInterrupts(){
    for(int i=0;i<sizeof(IN->__IN__);i++){
         IN->__IN__[i]='\0';
    	 IN->__INPUT_DONE=false;
   	 IN->__pointer=0;
   }
    asm volatile("sti");
}

void DisableInterrupts(){
  IN->__INPUT_DONE=false;
  asm("cli");
  sti=0;
}
