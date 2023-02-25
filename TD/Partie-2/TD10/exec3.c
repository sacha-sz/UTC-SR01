#include <stdio.h>
#include <stdlib.h>

void my_system(char * path, char ** argv) {
  pid_t pid = fork();
  if(pid == 0)
    execv(path, argv);
  else
    wait(0);
    return;
}

int main () {
  char * path = "/bin/ls";
  char * argv1 [] = {"ls", "-la", NULL};
  char * argv2 [] = {"bash", "-c", "/bin/ls *.c", NULL};


  printf("All files :\n");
  my_system(path, argv1);
  printf("\n\nOnly C file :\n");
  my_system("/bin/bash", argv2);

  return 0;
}
