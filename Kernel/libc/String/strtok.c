#include <stdio.h>
#include <string.h>

void print_str_decimal(char *x,int y){
	for(int i=0;i<y;i++){
		printo("%d: %c\t%d\n",i,x[i],x[i]);
	}
}

char *strtok(char *ret, char *delim){
	int ret_size=strlen(ret);
	int delim_size=strlen(delim);
	int x=0;
	char *charret;
	char *set=ret;
	int i=0;
	while(x<ret_size){
		if(ret[x]==delim[0]){
			print_str_decimal(charret,ret_size);			
			return charret;
		}
		charret[x]=ret[x];
		x++;
	}
}
