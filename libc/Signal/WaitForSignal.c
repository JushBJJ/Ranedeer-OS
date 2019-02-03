#include <signal.h>

int WaitForSignal(int SignalNum){
  for(;;){
    if(Current_Signal_Num!=SIG_NULL){
      break;
    }
  }

  if(Current_Signal_Num==SignalNum){
    Current_Signal_Num=SIG_NULL;
    SignalCollected=1;
    return SignalNum;
  }

  Current_Signal_Num=SIG_NULL;
  SignalCollected=1;
  return SIG_NULL;
}
