#include "stdio.h"
#include "stdlib.h"

#define N 5
#define M 5


// Affiche les informations d'une liste d'entiers
void matrice_info (int **matrice)
{
    int nb_pos=0, nb_neg =0, nb_zero =0;

    for (size_t i = 0; i < N; i ++)
    {
        printf("|");
        for (size_t j = 0; j < M; j ++)
        {
            printf(" %+d ",matrice[i][j]);
            if (matrice[i][j] > 0)
            {
                nb_pos ++;
            }
            else if (matrice[i][j] < 0)
            {
                nb_neg ++;
            }
            else
            {
                nb_zero ++;
            }
        }
        printf("|\n");
    }

    printf("\n\n\tInformations :\nNombre de positifs: %d\n", nb_pos);
    printf("Nombre de negatifs: %d\n", nb_neg);
    printf("Nombre de zeros: %d\n", nb_zero);

    if (nb_zero >= 0.8 * N * M)
    {
        printf("Matrice creuse\n");
    }
    else
    {
        printf("Matrice non creuse\n");
    }

}





int main ()
{
    /// Initialisation de la matrice avec des valeurs aléatoires
    int **matrice = (int **) malloc(N * sizeof(int *));
    for (size_t i = 0; i < N; i ++)
    {
        matrice[i] = (int *) malloc(M * sizeof(int));
        for (size_t j = 0; j < M; j ++)
        {
            matrice[i][j] = rand() % 100 - 60;
        }
    }

    matrice_info(matrice);

}