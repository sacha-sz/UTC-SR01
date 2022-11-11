#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/// Jeu des allumettes
void affiche_allumettes(int nb);
void affiche_tour (int compteur, int nb_allu_rest);
void affiche_score(int compteur_partie, int compteur_victoire);

int jeu_ordi (int nb_allum, int prise_max);
int jeu_humain (int nb_allum, int prise_max);
int saisie_nb_allu_max(void);
int saisie_nb_allu_saisie_max(int nb_max_d);
int choix_premier_joueur(void);
int victoire(int qui);
int choix_rejouer(void);


int main () {

    /**** Déclaration des variables ****/
    int nb_max_d=0; /*nbre d'allumettes maxi au départ*/
    int nb_allu_max=0; /*nbre d'allumettes maxi que l'on peut tirer au maxi*/
    int qui=0; /*qui joue? 0=Nous --- 1=PC*/
    int prise=0; /*nbre d'allumettes prises par le joueur*/
    int nb_allu_rest=0; /*nbre d'allumettes restantes*/
    int compteur_tour = 0;
    int compteur_victoire = 0;
    int compteur_partie = 0;
    int stop = 0;

    int nb_max_d_c = 0;

    /**** Début du programme ****/
    printf("---\t\tDebut du jeu\t\t---\n");

    nb_max_d_c = saisie_nb_allu_max();
    nb_allu_max = saisie_nb_allu_saisie_max(nb_max_d_c);


    while (stop == 0) {
        compteur_partie++;
        compteur_tour = 0;

        qui = choix_premier_joueur();
        nb_allu_rest = nb_max_d_c;

        while (nb_allu_rest > 1) {
            compteur_tour++;

            affiche_tour(compteur_tour, nb_allu_rest);

            if (qui == 0) {
                prise = jeu_humain(nb_allu_rest, nb_allu_max);
            } else {
                prise = jeu_ordi(nb_allu_rest, nb_allu_max);

            }

            nb_allu_rest = nb_allu_rest - prise;
            qui = abs(qui - 1);
        }
        compteur_victoire += victoire(qui);

        stop = abs(choix_rejouer()-1);
    }

    affiche_score(compteur_partie, compteur_victoire);
}

void affiche_allumettes(int nb)
{
    if (nb == 0) printf("Partie finie");

    for (size_t i = 0; i < nb; i ++)
    {
        printf("O  ");
    }
    printf("\n");

    for (size_t i = 0; i < nb; i ++)
    {
        printf("|  ");
    }
    printf("\n");
}

int jeu_ordi (int nb_allum, int prise_max)
{
    int prise = 0;
    int s = 0;
    float t = 0;

    s = prise_max + 1;
    t = ((float) (nb_allum - s)) / ((float) prise_max + 1);
    while (floor (t) != t)
    {
        s--;
        t = ((float) (nb_allum-s)) / ((float) prise_max + 1);
    }
    prise = s - 1;

    if (prise == 0)
        prise = 1;

    printf("\nLe PC tire %d allumettes\n",prise);

    return (prise);
}


int saisie_nb_allu_max(void)
{
    int max =0;

    printf("\nCombien d'allumettes au depart?  (de 10 a 60)\n");
    scanf("%d",&max);
    while (max < 10 || max > 60) {
        printf("Erreur, veuillez entrer un nombre entre 10 et 60\n");
        scanf("%d",&max);
    }

    return max;
}

int saisie_nb_allu_saisie_max(int nb_max_d)
{
    int max =0;
    printf("\nCombien d'allumettes au maximum par tour? (compris entre 1 et nb_max-1)\n");
    scanf("%d",&max);
    while (max < 1 || max >= nb_max_d) {
        printf("Erreur, veuillez entrer un nombre entre 1 et %d\n",nb_max_d);
        scanf("%d",&max);
    }

    return max;
}


int jeu_humain (int nb_allum, int prise_max)
{
    int prise = 0;
    printf("\nCombien d'allumettes voulez-vous tirer? ");
    scanf("%d",&prise);

    while (prise>nb_allum || prise<1 || prise_max-prise<0) {
        printf("\nVous ne pouvez pas tirer %d allumettes",prise);
        printf("\nLe nombre d'allumettes doit etre compris entre 1 et %d et le nombre d'allumettes restantes doit etre positif",prise_max);
        printf("\nCombien d'allumettes voulez-vous tirer? ");
        scanf("%d",&prise);
    }

    return prise;
}

void affiche_tour (int compteur, int nb_allu_rest)
{
    printf("\n---------- Tour %d ----------\n",compteur);

    printf("\nIl reste %d allumettes\n",nb_allu_rest);
    affiche_allumettes(nb_allu_rest);
}

int choix_premier_joueur(void)
{
    int choix = 0;
    printf("\nQui commence? (0=Vous --- 1=PC)\n");
    scanf("%d",&choix);
    while (choix != 0 && choix != 1) {
        printf("Erreur, veuillez entrer 0 ou 1\n");
        scanf("%d",&choix);
    }

    return choix;
}

int victoire(int qui)
{
    if (qui==0) {
        printf("\nVous avez perdu :(");
    }
    else
    {
        printf("\nVous avez gagne!! :)");
    }

    return qui;
}

int choix_rejouer(void)
{
    int choix = 0;
    printf("\nVoulez-vous rejouer? (0=Non --- 1=Oui)\n");
    scanf("%d",&choix);

    while (choix != 0 && choix != 1) {
        printf("Erreur, veuillez entrer 0 ou 1\n");
        scanf("%d",&choix);
    }

    return choix;
}

void affiche_score(int compteur_partie, int compteur_victoire)
{
    printf("\nVous avez joue %d parties et gagne %d parties",compteur_partie,compteur_victoire);
    printf("\nSoit un pourcentage de victoire de %f",(((float) compteur_victoire)/(float) compteur_partie)*100);
}
