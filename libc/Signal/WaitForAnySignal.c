#include <signal.h>

void WaitForAnySignal(int Get){
    for(;;){
      if(Current_Signal_Num!=SIG_NULL)
        break;
    }
    Get=Current_Signal_Num;
    Current_Signal_Num=SIG_NULL;
    SignalCollected=1;
}
