int strlen(char *str){
  int i = 0;
  
  for(; str[i]!=0x00 || str[i]!=0x13; i++){}
  return i;
}
