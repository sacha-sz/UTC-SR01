#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"


int main () {
  printf("PID : %ld\n", getpid());
  printf("PPID : %ld\n", getppid());
  printf("UID : %ld\n", getuid());
  printf("GID : %ld\n", getgid());

  return 0;
}