#include "stdio.h"
#include "stdlib.h"

#define TAILLE 10
#define NBMAX 3


int main ()
{
    int val;
    // Dessine un sapin de 10 etages
    for (int i=0; i < TAILLE; i++) {
        for (int j = 0; j < NBMAX; j++) {
            // Dessine les espaces
            for (int k = 0; k < TAILLE - i; k++)
                printf(" ");

            // Dessine les etoiles
            for (int k = 0; k < 2 * i + 1; k++) {
                val = rand() % 8;
                if (val >= 0 && val <= 3)
                    printf("8");
                else if (val >= 4 && val <= 6)
                    printf("*");
                else
                    printf("o");
            }
            for (int k = 0; k < 10 - i; k++)
                printf(" ");


        }
        printf("\n");

    }

    // Dessin du tronc de taille 4
    for (int k = 0; k < TAILLE / 4; k++){
        for (int i=0; i < NBMAX; i++) {
            for (int j = 0; j < TAILLE - TAILLE / 4; j++)
                printf(" ");

            for (int j = 0; j < TAILLE / 2; j++)
                printf("|");

            for (int j = 0; j < TAILLE - TAILLE / 4; j++)
                printf(" ");


        }
        printf("\n");
    }

    return 0;
}