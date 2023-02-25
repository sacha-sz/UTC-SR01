#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main () {
  int compteur = 0;
  while (*environ) {
    compteur++;
    printf("La variable [%d] : %s\n", compteur, *environ);
    *environ++;
  }

  printf("Il y a %d variables d'environnement\n", compteur);

  return 0;
}
