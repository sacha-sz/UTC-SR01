#include "ex4.h"
#include <stdio.h>
#include <stdlib.h>


void Affiche_c (Complexe c)
{
    if (c.y < 0)
        printf("%f %fi", c.x, c.y);
    else if (c.y == 0)
        printf("%f", c.x);
    else
        printf("%f + %fi", c.x, c.y);
}

Complexe somme (Complexe c1, Complexe c2)
{
    Complexe c;
    c.x = c1.x + c2.x;
    c.y = c1.y + c2.y;
    return c;
}

Complexe multiplication (Complexe c1, Complexe c2)
{
    Complexe c;
    c.x = c1.x * c2.x - c1.y * c2.y;
    c.y = c1.x * c2.y + c1.y * c2.x;
    return c;
}

nombre saisir_nombre()
{
    printf("Quel type de nombre voulez-vous saisir ?\n");
    printf("1. Entier\n");
    printf("2. Réel\n");
    printf("3. Complexe\n");
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);

    nombre n;

    switch (choix)
    {
        case 1:
            n.type = entier;
            printf("Entrez un entier : ");
            scanf("%d", &n.valeur.entier);
            break;

        case 2:
            n.type = reel;
            printf("Entrez un réel : ");
            scanf("%f", &n.valeur.reel);
            break;

        case 3:
            n.type = complexe;
            printf("Entrez un complexe : ");
            printf("Partie réelle : ");
            scanf("%f", &n.valeur.complexe.x);
            printf("Partie imaginaire : ");
            scanf("%f", &n.valeur.complexe.y);
            break;

        default:
            printf("Erreur de saisie\n");
            exit(1);
    }
}

void afficher_nombre(nombre n)
{
    switch (n.type)
    {
        case entier:
            printf("Entier : %d\n", n.valeur.entier);
            break;

        case reel:
            printf("Réel : %f\n", n.valeur.reel);
            break;

        case complexe:
            printf("Complexe : ");
            Affiche_c(n.valeur.complexe);
            printf("\n");
            break;

        default:
            printf("Erreur de saisie\n");
            exit(1);
    }
}
