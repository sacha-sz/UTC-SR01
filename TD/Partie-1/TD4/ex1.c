#include "stdio.h"
#include "stdlib.h"

void etude_char (char * mot)
{
    int long_chaine = 0, car_maj = 0, car_min = 0, nb_espace = 0, nb_autre = 0;

    while (mot[long_chaine] != '\0')
    {
        if (mot[long_chaine] >= 'A' && mot[long_chaine] <= 'Z')
            car_maj++;
        else if (mot[long_chaine] >= 'a' && mot[long_chaine] <= 'z')
            car_min++;
        else if (mot[long_chaine] == ' ')
            nb_espace++;
        else if (mot[long_chaine] == '\t' || mot[long_chaine] == '\n')
        {
            long_chaine++;
            continue;
        }
        else
            nb_autre++;

        long_chaine++;
    }

    printf("La chaine contient %d caracteres majuscules, %d caracteres minuscules, %d espaces et %d autres caracteres.", car_maj, car_min, nb_espace, nb_autre);

}

int main ()
{
    char mot[20];

    printf("Entrez un mot : ");
    fgets(mot, 20, stdin);

    etude_char(mot);
    return 0;
}