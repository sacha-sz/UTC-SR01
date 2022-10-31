#include "mystr.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main()
{
    char * S1 = "ABcd";
    char *S2;
    S2 = malloc(sizeof(0));

    printf("*** MENU ***\n");
    printf("\t1.mystrupdown\n\t2.mystrinv\n\t3.mystrchrn\n\t4.mystrncpy\n\t5.mystrncat\n");
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);
    while(getchar() != '\n');
    printf("\n");

    switch (choix)
    {
        case 1:
            mystrupdown(S1, S2);
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

        case 4:
            mystrncpy(S1, S2, 2);
            printf("S1 = %s\nS2 = %s\n", S1, S2);
            break;

        case 5:
            mystrncat(S1, S2, 2);
            printf("S1 = %s\nS2 = %s\n", S1, S2);
            break;

        default:
            printf("Choix invalide\n");
            break;
    }
}
