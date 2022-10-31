#include <stdlib.h>
#include <stdio.h>

int main () {
    int p[4] = {1, -2, 3, 4};
    int *q = p;
    int d = *q & *q++ | *q++ ;

    /*Explication:
     * 1. *q : 1
     * 2. *q++ : 1 et q est incrémenté (post incrément donc q pointe vers -2)
     * 3. *q++ : -2 et q est incrémenté (post incrément donc q pointe vers 3)
     * *q & *q++ | *q++ <===> 1 & 1 | -2 <===> 1 | -2
     * En binaires : 0001 & 0001 | 1110 <===> 0001 | 1110 <===> 1111 = -1
     *
     * Fin :
        *  d vaut -1
        *  q pointe vers 3 (après la double incrémentation)
     */
     
    printf("d = %d\n", d);
    printf("q = %d\n", *q);
}
