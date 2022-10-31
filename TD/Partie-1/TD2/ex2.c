#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>

void creation ()
{
    // Création d'un tableau de 10 entiers
    int tab[MAX];
    for (int i = 0; i < MAX; ++i) {
        tab[i] = i + VAL;
    }

    // Affichage du tableau
    for (int i = 0; i < MAX; ++i) {
        printf("%d ", tab[i]);
    }
}
