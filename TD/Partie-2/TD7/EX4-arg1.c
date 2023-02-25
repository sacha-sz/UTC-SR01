#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[], char *envp []) {
  int compteur = 0;
  while (*envp) {
    compteur++;
    printf("La variable [%d] : %s\n", compteur, *envp);
    *envp++;
  }

  printf("Il y a %d variables d'environnement\n", compteur);

  return 0;
}
