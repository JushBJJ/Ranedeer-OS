#ifndef UTILS_H
  #define UTILS_H
  #include <other/types.h>
  void memcp(char *source,char *destination, int bytes);
  void ToAscii(int num, char target[]);
  char ToAsciiRet(int num);
  int strlen(char s[]);
  void AddtoChar(char s[],char c);
  void BackspaceChar(char s[]);
  void memset(u8 *dest,u8 val,u32 len);
  int GetCharSize(char *target);
#endif
