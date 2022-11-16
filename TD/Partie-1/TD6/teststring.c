#include "mystrinv.h"
#include "mystrchrn.h"
#include "mystrshow.h"


int  main(void) {
    char S1[50];
    char S2[50];

    printf("*** MENU ***\n");
    /*** Saisie de la chaine S1 ***/
    printf("S1 : Saisir une chaine de caracteres : ");
    scanf("%s", S1);
    printf("S2 : Saisir une chaine de caracteres : ");
    scanf("%s", S2);

    printf("\t1.mystrinv\n\t2.mystrinv\n\t3.mystrchrn\n");
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);
    while(getchar() != '\n');
    printf("\n");

    switch (choix)
    {
        case 1:
            mystrinv(S1, S2);
            printf("S1 = %s\nS2 = %s\n", S1, S2);
            break;

        case 2:
            mystrinv(S1, S2);
            printf("S1 = %s\nS2 = %s\n", S1, S2);
            break;

        case 3:
            printf("S1 = %s\nS2 = %s\n", S1, S2);
            printf("Le nombre de fois que le caractère 'c' apparait dans S1 est : %d\n", mystrchrn(S1, 'c'));
            break;

        default:
            printf("Choix invalide\n");
            break;
    }
}

