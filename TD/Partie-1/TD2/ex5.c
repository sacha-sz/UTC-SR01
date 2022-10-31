#include "ex5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Etudiant sr01[NBRE_ETUDIANTS];

struct Etudiant* creer_etu (char * nom, char * prenom, char * n_compte)
{
    struct Etudiant * etu = malloc(sizeof(struct Etudiant));

    if (etu == NULL)
    {
        printf("Erreur d'allocation mémoire");
        exit(1);
    }

    if (nom == NULL || strlen(nom) > 20)
    {
        printf("Erreur sur le nom");
        exit(1);
    }
    else if (prenom == NULL || strlen(prenom) > 20)
    {
        printf("Erreur sur le prenom");
        exit(1);
    }
    else if (n_compte == NULL || strlen(n_compte) > 7)
    {
        printf("Erreur sur le n_compte");
        exit(1);
    }

    strcpy(etu->nom, nom);
    strcpy(etu->prenom, prenom);
    strcpy(etu->n_compte, n_compte);

    return etu;
}

struct Etudiant Saisir_etudiant()
{
    printf("Vous allez saisir un étudiant\n");
    printf("Nom : ");
    char nom[20];
    scanf("%s", nom);


    printf("Prenom : ");
    char prenom[20];
    scanf("%s", prenom);

    printf("N_compte : ");
    char n_compte[7];
    scanf("%s", n_compte);

    return *creer_etu(nom, prenom, n_compte);
}

void affiche_etu (struct Etudiant etu)
{
    printf("Nom : %s\n", etu.nom);
    printf("Prenom : %s\n", etu.prenom);
    printf("N_compte : %s\n", etu.n_compte);
}