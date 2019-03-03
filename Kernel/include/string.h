#ifndef STRING_H
  #define STRING_H
  #include <types.h>

  static int ptr;

  int strlen(char *str);
  void IntToAscii(int num, char target[]);
  int strcmp(const char* s1,const char *s2);
  char *strtok(char *str,char *delim);
  char *strncpy(char *dest, const char *f,size_t n);
  char *strcpy(char *dest,char *f);
  str_t strstr(char* str,char* sub);
  char *itoa(int val);
  int strcspn(char *text,char target);
#endif
