#ifndef STRING_H
  #define STRING_H
  #include <types.h>

  static int ptr;
  static int pointer = 0; //Pointer used for OG_String, it will get reset back to 0 when OLD_NEW is equal to 1
  static char *OG_String; //Static just in case, but will get reset when OLD_NEW is equal to 1

  int strlen(char *str);
  void IntToAscii(int num, char target[]);
  int strcmp(const char* s1,const char *s2);

  char *strtok(char *Original_String, const char Split_C, bool OLD_NEW);
  char *strtok_new(char *Original_String, const char Split_C);
  char *strtok_old(char *Original_String, const char Split_C);
  
  void m_strcpy(char *x, char *y)
  char *strncpy(char *dest, const char *f,size_t n);
  char *strcpy(char *dest,char *f);
  str_t strstr(char* str,char* sub);

  char *itoa(int val);
  int strcspn(char *text,char target);
#endif
