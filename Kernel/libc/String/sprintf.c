#include <stdio.h>
#include <stdarg.h>

void sprintf_v(va_list ap,char *target,char *format){
	int x=0;

	int pointer=0;
	char *str;
	char c;
	
	/* Clear the target first */
	while(x<sizeof(target)){
		target[x]='\0';
		x++;
	}

	while(format[pointer]!='\0'){
		if(format[pointer]=='%'){
			pointer++;
			switch(format[pointer]){
				case 's':
					pointer++;
					str=va_arg(ap,char *);
					if(str[0]!='\0'){
						sprintf(target,str);
					}
					break;
				case 'c':
					pointer++;
					c=va_arg(ap,char);
					if(str[0]!='\0'){
						str[0]=c;
						str[1]='\0';
						sprintf(target,str);
					}
					break;
				case 'd':
					pointer++;
					x=va_arg(ap,int);
					str=itoa(x);
					sprintf(target,str);
					break
				default:
					pointer--;
					target[pointer]=format[pointer];
					pointer++;
					break
			}
		}
		else{
			target[pointer]=format[pointer];
			pointer++;
		}

	}				
}

void sprintf(char *target,char *format,..){
	va_list ap;
	va_start(ap,format);
	sprintf_v(ap,target,format);
	va_end(ap);
}
	
