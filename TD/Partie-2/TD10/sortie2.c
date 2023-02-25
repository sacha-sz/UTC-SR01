#include <stdio.h>
#include <stdlib.h>

void fonc () {
  printf("PHASE TERMINALE**\n");
  for (int i = 0; i < 15; i++)
    printf("*");
  printf("\n");
}

int main () {
  int rep;
  printf("Entrez un nombre : ");
  scanf("%d", &rep);

  atexit(fonc);

  if (5 <= rep && rep <= 10)
    exit(0);
  else
    exit(1);

  return 0;
}
