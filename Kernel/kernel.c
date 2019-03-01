#include <string.h>
#include <stdio.h>
#include <isr.h>
#include <string.h>
#include <color.h>
#include <timer.h>
#include <Shell.h>

void startkernel(){
  	clear();
  	printo("%kKernel Loading\n",White_Text);
  	/* Interrupt Initialization */
  	I_CK->Keyboard=false;
  	I_CK->Call=true; /* ON BY DEFAULT */
	isr_install();

	initTimer(50);
	initKeyboard();

	EnableInterrupts();
  	printk("Kernel: Interrupts [%kSyscall%k] %k%b%k\n",Light_Green_Text,White_Text,Light_Green_Text,I_CK->Call,White_Text);
	printk("Kernel: Interrupts [%kKeyboard%k] %k%b%k\n",Light_Green_Text,White_Text,Light_Red_Text,I_CK->Keyboard,White_Text);

	printk("Loading Shell.\n");
	Start_Shell();	
}
