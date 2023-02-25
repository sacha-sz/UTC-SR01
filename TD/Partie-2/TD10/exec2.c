#include <stdio.h>
#include <stdlib.h>

void my_system(char * path, char ** argv) {
  execv(path, argv);
}

int main () {
  char * path = "/bin/ls";
  char * argv1 [] = {"ls", "-la", NULL};
  char * argv2 [] = {"ls", "*.c", NULL};


  printf("All files :\n");
  my_system(path, argv1);
  printf("\n\nOnly C file :\n");
  my_system(path, argv2);

  return 0;
}
