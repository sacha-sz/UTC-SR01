#include <stdio.h>
#include <stdlib.h>

int main () {
  int rep;
  printf("Entrez un nombre : ");
  scanf("%d", &rep);

  if (5 <= rep && rep <= 10)
    exit(0);
  else
    exit(1);

  return 0;
}
