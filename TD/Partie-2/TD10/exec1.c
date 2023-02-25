#include <stdio.h>
#include <stdlib.h>

int main () {
  printf("All files :\n");
  system("/bin/ls -la");
  printf("\n\nOnly C file :\n");
  system("/bin/ls *.c");

  return 0;
}
