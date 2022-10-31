#include "stdio.h"
#include "stdlib.h"

char  *jour[7] = {"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};


int main()
{
    printf("Saisissez l'indice du premier jour du mois :\n");
    printf("0 : lundi \n1 : mardi \n2 : mercredi \n3 : jeudi \n4 : vendredi \n5 : samedi \n6 : dimanche \n");
    printf("Votre choix : ");

    int indice = 0;
    scanf("%d", &indice);

    int saisie_verif = 1;
    int date;

    while (saisie_verif == 1)
    {
        printf("Entrez la date du jour : ");
        scanf("%d", &date);

        if (date <= 0 || date > 31)
        {
            printf("Date incorrecte (comprise entre 1 et 31, veuillez recommencer.\n");
        }
        else
        {
            saisie_verif = 0;
        }
    }

    printf("Le %d du mois est un %s", date, jour[(date + indice)%7]);
}
