#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int nb, char *arg[])
{
    if(nb<4) {
        printf("il vous manque des arguments \n");
        return 0;
    }


    double resultat = 0;

    int i;

    if(strcmp(arg[1],"-a")==0)
    {
        resultat=0;
        for(i=2;i<nb;i++)
            resultat+= atof(arg[i]);

        printf("la somme= ");
    }
    else if (strcmp(arg[1],"-p")==0){
        resultat=1;
        for(i=2;i<nb;i++)
            resultat*= atof(arg[i]);

        printf("le produit= ");

    }
    else if(strcmp(arg[1],"-d")==0)
    {
        resultat=atof(arg[2]);
        for(i=3;i<nb;i++)
            resultat/= atof(arg[i]);

        printf("la division= ");
    }

    else
    {
        printf("opération non reconnue \n");
        return 0;
    }

    printf("%f \n",resultat);

    return 0;
}