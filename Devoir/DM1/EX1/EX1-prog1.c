#include <stdlib.h>
#include <stdio.h>

int main (){
    int A = 20, B = 5;
    int C=!-- A / ++ !B;
    
    /*
     * Explication:
     * 1. !--A <=> !19 <=> 0
     * 2. ++ !B <=> ++ !5 <=> ++ 0 <=> erreur car 0 est une rvalue
     * Fin : A vaut 19, B vaut 5, C génère une erreur
     */

    printf ("A=%d B=%d C=%d \n", A, B, C);
}
