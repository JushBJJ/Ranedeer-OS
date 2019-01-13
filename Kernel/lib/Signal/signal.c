#include <Signal/signal.h>
#include <io/Ranedeerio.h>

static int Current_Signal_Num=SIG_NULL;

void SendSignal(int SignalNum){
  Current_Signal_Num=SignalNum;
  printo("Signal Sent: ");
  printnum(SignalNum);
  printo("\n");
}

int WaitForSignal(int SignalNum){
  for(;;){
    if(Current_Signal_Num!=SIG_NULL){
      break;
    }
  }

  if(Current_Signal_Num==SignalNum){
    return SignalNum;
  }

  printo("Signal: ");
  printnum(Current_Signal_Num);

  Current_Signal_Num=SIG_NULL;
  return SIG_NULL;
}
