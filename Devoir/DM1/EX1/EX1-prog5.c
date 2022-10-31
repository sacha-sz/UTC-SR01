#include <stdlib.h>
#include <stdio.h>

int main (){
    int a = -8, b=3;
      int c =++a&&--b ? b--:a++;

    /*Explication :
     * 1. ++a <=> a = -7
     * 2. --b <=> b = 2
     * 3. ++a&&--b <=> -7 && 2 <=> 1
     * 4. b-- <=> b = 1 post incrément donc c prend la valeur de b avant l'incrément donc c = 2 et b = 1
     * Bilan : a = -7, b = 1 et c = 2
     */
     
    printf("a=%d b=%d c=%d\n", a, b, c);
}
