#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  char s[20];
  printf("Entrez le nom de la variable :\n");
  scanf("%s", s);

  char *chaine = getenv(s);
  int taille =strlen(chaine) + 9;
  char copie[taille];
  for (size_t i = 0; i < taille - 9 ; i++ ) {
    copie[i] = chaine [i];
  }

  printf("%s\n", copie);
  char modifie[] = " modifie";
  for (size_t i = taille - 9 ; i < taille ; i++) {
    copie[i] = modifie[i%10];
  }

  printf("%s\n", copie);

  return 0;
}
