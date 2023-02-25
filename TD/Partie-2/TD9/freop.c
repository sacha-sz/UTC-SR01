#include <stdio.h>

int main(){
  FILE *fa;
  printf("Avant freopen\n");
  fa = freopen("freop.txt", "a+", stdout);

  if (fa == NULL) {
    perror("freopen erreur :");
    exit(0);
  }

  printf("Apres freopen\n");

  fclose(fa);

  printf("Apres fclose\n");
  fa = freopen("/dev/tty", "a+", stdout);
  printf("Apres freopen(/dev/tty)\n)");


  return 0;
}
