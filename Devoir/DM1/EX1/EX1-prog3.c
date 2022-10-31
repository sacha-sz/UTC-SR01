#include <stdlib.h>
#include <stdio.h>

int main (){
    int p[4]={1,-2,3,4};
    int *q=p;

    printf("c=%d\n", *++q**q++);

    /* Explication :
     * 1. *++q : -2 et q est incrémenté (pre incrément donc q pointe vers -2)
     * 2. *q++ : -2 et q est incrémenté (post incrément donc q pointe vers 3)
     * 3. *++q**q++ : -2 * -2 = 4
     *
     * Fin:
        * affiche 4
        * q pointe vers 3
     */
     
    printf("c=%d\n", *q);
}
