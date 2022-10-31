#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

#include "wchar.h"

#define LINE 50
#define COLUMN 50

/// Jeu de la vie
void init_matrice (int mat[LINE][COLUMN]);
void affiche_matrice (int mat[LINE][COLUMN]);
int change_matrice(int mat[LINE][COLUMN]);

int est_non_vide(int mat[LINE][COLUMN]);

int main()
{

    int mat[LINE][COLUMN];
    int changement = 1;
    init_matrice(mat);


    while (est_non_vide(mat) == 0 && changement == 1)
    {
        affiche_matrice(mat);
        changement = change_matrice(mat);
        system("cls");
    }
}


// Initialisation de la matrice de taille LINE x COLUMN
void init_matrice (int mat[LINE][COLUMN])
{
    for (size_t i =0; i < LINE; i++)
    {
        for (size_t j =0; j < COLUMN; j++)
        {
            mat[i][j] = rand() % 2;
        }
    }
}

void affiche_matrice (int mat[LINE][COLUMN])
{
    wchar_t white = 178;
    wchar_t black = 176;

    for (size_t i =0; i < LINE; i++)
    {
        for (size_t j =0; j < COLUMN; j++)
        {

            switch (mat[i][j])
            {
            case 0:
                wprintf(L"%c%c ", black, black);
                break;


            case 1:
                wprintf(L"%c%c ", white, white);
                break;

            default:
                break;
            }
        }
        printf("\n");
    }

    sleep(2);
}

int change_matrice(int mat[LINE][COLUMN])
{
    int changement = 0;
    int init[LINE][COLUMN];

    for (size_t i =0; i < LINE; i++)
    {
        for (size_t j =0; j < COLUMN; j++)
        {
            init[i][j] = mat[i][j];
        }
    }

    int nb_voisin = 0;

    for (size_t i =0; i < LINE; i++)
    {
        for (size_t j =0; j < COLUMN; j++)
        {
            // Calcul du nombre de voisins
            nb_voisin = 0;

            for (int ligne = -1; ligne <2; ligne++)
            {
                for (int col = -1; col < 2; col++)
                {
                    if (init[(i + ligne + LINE)%LINE][(j + col + COLUMN)%COLUMN])
                    {
                        nb_voisin++;
                    }
                }
            }

            // Changement valeur ou non
            switch (nb_voisin)
            {
                case 0:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 1:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 2:
                    break;

                case 3:
                    if (init[i][j] == 0)
                    {
                        mat[i][j] = 1;
                        changement = 1;
                    }
                    break;

                case 4:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 5:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 6:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 7:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;

                case 8:
                    if (init[i][j] == 1)
                    {
                        mat[i][j] = 0;
                        changement = 1;
                    }
                    break;


                default:
                    break;
            }

        }
    }

    return changement;
}

int est_non_vide (int mat[LINE][COLUMN])
{
    int fin = 1;

    for (size_t i =0; i < LINE; i++)
    {
        for (size_t j =0; j < COLUMN; j++)
        {
            if (mat[i][j] == 1)
            {
                fin = 0;
            }
        }
    }

    return fin;
}