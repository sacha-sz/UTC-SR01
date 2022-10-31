#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"
#include "ex4.h"

void affiche_type ()
{
    // Affiche pour tous les types : type = sa taille en mémoire (sizeof)
    printf("int = %llu\n", sizeof(int));
    printf("char = %llu\n", sizeof(char));
    printf("float = %llu\n", sizeof(float));
    printf("double = %llu\n", sizeof(double));
    printf("void = %llu\n", sizeof(void));
    printf("long = %llu\n", sizeof(long));
    printf("short = %llu\n", sizeof(short));
}

int main() {
    affiche_type();
    creation();


    Complexe c;
    c.x = 1;
    // c.y = 2;
    // c.y = 0;
    c.y = -2;
    Affiche_c(c);

    Complexe c1, c2, c3;

    c1.x = 1;
    c1.y = 2;
    c2.x = 3;
    c2.y = 4;

    c3 = somme(c1, c2);
    c3 = multiplication(c1, c2);
    Affiche_c(c3);



    return 0;
}