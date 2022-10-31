#include <stdlib.h>
#include <stdio.h>

int main (){
    int a =-8, b=3;

    a >>=2^b;

    /* Explication:
     * 1. a = -8 en binaire : 1111 1000
     * 2. 2^b : 10 ^ 11 = 01 = 1
     * 3. a >>=2^b : 1111 1000 >> 1 = 1111 1100 = -4
     *
     * Fin:
        * a = -4
     */
     
    printf("a=%d\n", a);
}
