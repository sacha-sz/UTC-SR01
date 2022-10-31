#include "stdio.h"
#include "stdlib.h"

#define N 5
#define M 5


// Affiche les informations d'une liste d'entiers
void matrice_info (int matrice[N][M])
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

int matrice_creuse (int matrice[N][M], int vect[N*M])
{
    int nb_zero = 0;
    size_t k = 0;
    for (size_t i = 0; i < N; i ++)
    {
        for (size_t j = 0; j < M; j ++)
        {
            if (matrice[i][j] == 0)
            {
                nb_zero ++;
            }
            else
            {
                vect[k++] = matrice[i][j];
            }
        }
    }

    if (nb_zero >= 0.8 * N * M)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main ()
{
    /// Initialisation de la matrice avec des valeurs aléatoires
    int matrice[N][M];
    for (size_t i = 0; i < N; i ++)
    {
        for (size_t j = 0; j < M; j ++)
        {
            matrice[i][j] = rand() % 10 - 7;
        }
    }

    //matrice_info(matrice);

    int vect[N*M];

    if (matrice_creuse(matrice, vect) == 1)
    {
        printf("Matrice creuse\n");
    }
    else
    {
        printf("Matrice non creuse\n");
    }
}