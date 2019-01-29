global test

test:
  mov eax,1
  push eax
  int 0x20
  ret
