#include <signal.h>
#include <stdio.h>

void SendSignal(int SignalNum){
  Current_Signal_Num=SignalNum;
}
