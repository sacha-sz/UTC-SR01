#include "stdio.h"
#include "stdlib.h"

#define TAILLE 50

int main ()
{
    // Dessine un sapin de 10 etages
    for (int i = 0; i < TAILLE; i++)
    {
        // Dessine les espaces
        for (int j = 0; j < TAILLE - i; j++)
            printf(" ");

        // Dessine les etoiles
        for (int j = 0; j < 2 * i + 1; j++)
                printf("*");

        printf("\n");
    }

    // Dessin du tronc de taille 4
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAILLE - TAILLE/4; j++)
            printf(" ");

        for (int j = 0; j < TAILLE/2; j++)
            printf("|");

        printf("\n");
    }

    return 0;
}