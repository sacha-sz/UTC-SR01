#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    int x = 10;
    int y, z;
    x *= y = z = 4; // z vaut 4 puis y vaut 4 puis x vaut 40

    printf("x = %d \n",x);
}


int main(void)
{
    int x, y, z;
    x = 2; y = 1; z = 0; // x vaut 2, y vaut 1 et z vaut 0
    x = x && y || z; // x vaut 1
    printf("x = %d \n",x);
}

int main(void)
{
    int x = 2, y = 1, z = 0;
    z += -x++ + ++y; // x vaut 2 (puis post opération 3), y vaut 1+1=2, on ajoute -2 + 2 à z, z vaut toujours 0
    printf("x=%d  y=%d  z=%d  \n",x, y, z);
}


int main(void)
{
    int x = 3, z = 0;
    z = x / ++x; // x vaut 3+1=4, on divise 4 par 4, z vaut 1
    printf("x=%d    z=%d  \n",x, z);
}


int main(void)
{
    int x = 03, y = 02, z = 01;
    int a, b;

    a = x | y & ~z;
    // OU binaire entre x et ET binaire entre y et NON binaire entre z
    // a = 3 | 2 & ~1
    // Soit en binaire :        11 | 10 & ~01 <==> 11 | 10 & 10 <==> 11 | 10 <==> 11
    // a = 3

    b = x ^ y & ~z;
    // OU EXCLUSIF binaire entre x et ET binaire entre y et NON binaire entre z
    // b = 3 ^ 2 & ~1
    // Soit en binaire :        11 ^ 10 & ~01 <==> 11 ^ 10 & 10 <==> 11 ^ 10 <==> 01
    // b = 1

    printf("a=%d  b=%d \n", a, b);
}

int main(void)
{
    int x = 01, y = -01;
    int a;
    a = ~x | x;
    // a = ~01 | 01 <==>  10 | 01 <==>  11
    // a = -1 car changement de signe (issue de la complément à 2 induite par le NON binaire)

    y <<= 3;
    // 01 << 3 <==> 01000 <==> 8
    // y = -8

    1111 1111 <===> 1111 1000
    1111 1000 <===> 0000 0111 + 1 <====> 0000 1000 <===> 8


    printf("a=%d  y=%d \n", a, y);
}


int main(void)
{
    int x = 3, y = 2;
    int a;
    a = x < y ? x++ : y++;
    printf("x=%d  y=%d a=%d \n", x, y, a);
}


int main(void)
{
    int x = -1, y = -1, z = -1;
    int a;
    a = ++x && ++y || ++z; // x vaut 0, y vaut 0, z vaut 0; a vaut 0
    // y n'est pas modifié puisque x est déjà nul le compilateur ne va pas chercher à l'executer
    printf("y=%d  a=%d \n", y, a);
}