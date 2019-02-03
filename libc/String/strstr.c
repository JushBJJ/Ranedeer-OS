#include <string.h>
#include <types.h>

str_t strstr(char* str,char* sub){
  size_t size_str=strlen(str);
  size_t size_sub=strlen(sub);

  char temp[size_sub];
  str_t return_str;

  int str_index=0;
  int found=0; /* False */
  int i=0;
  int index=0;

  while(str[index]){
    if(str[index]==sub[0]){
      i=0;
      for(;sub[i];i++){
        temp[i]=sub[i+index];
      }
      temp[i]='\0';
      if(!strcmp(temp,sub)){
        str_index=(i+index)-size_sub;
        found=1;
        for(int x=0;x<200;x++)
          return_str.str[i]=0;
        for(uint32_t x=str_index,j=0;x<size_str;x++,j++)
          return_str.str[j]=str[x];
      }
      index++;
    }
    else
      index++;
  }
  if(found==0)
    return_str.str[0]=0;
  return return_str;
}
