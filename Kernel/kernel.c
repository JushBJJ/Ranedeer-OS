#include <string.h>
#include <stdio.h>
#include <isr.h>
#include <string.h>
#include <color.h>
#include <timer.h>
#include <Shell.h>
#include <keyboard.h>

void startkernel(){
  	clear(); // Clear Screen
	
  	printo("%kKernel Loading\n",White_Text);
	
  	/* Interrupt Initialization */
  	I_CK->Keyboard=false; // Disable the keyboard
  	I_CK->Call=true; /* ON BY DEFAULT */
	isr_install(); //Install interrupts

	initTimer(50);
	initKeyboard();
	
	/* Just to make sure that all of the Key's arrays are 0x00000 */
	for(int i=0;i<sizeof(Key);i++){
		Key[i]=0x00;
	}
	
	EnableInterrupts(); // Enable Interrupts
	DisableKeyboard(); // Disable keyboard??? lol wat
		
  	printk("Kernel: Interrupts [%kSyscall%k] %k%b%k\n",Light_Green_Text,White_Text,Light_Green_Text,I_CK->Call,White_Text);
	printk("Kernel: Interrupts [%kKeyboard%k] %k%b%k\n",Light_Green_Text,White_Text,Light_Red_Text,I_CK->Keyboard,White_Text);
	
	Start_Shell(); // Start the shell..NOW
}
