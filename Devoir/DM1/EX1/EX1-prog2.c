#include <stdlib.h>
#include <stdio.h>

int main (){
    int A = 20, B = 5, C = -10, D = 2;

    printf("%d\n", A&&B||!0&&C++&&!D++);

    /* Explication :
     * 1. A&&B <=> 20&&5 <=> 1 donc le ou logique est évalué à 1 la suite n'est pas évaluée
     *
     * Fin :
        * Affiche 1 et C et D n'ont pas été incrémentés
        * A = 20, B = 5, C = -10 et D = 2
     */
     
    printf("c=%d, d=%d\n", C, D);
}
