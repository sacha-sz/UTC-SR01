#include "stdio.h"
#include "stdlib.h"

#define MAX 6

int tab1[MAX] = {6,4,5,10,8,2};
int tab2[MAX] = {7,8,9,1,2,3};
int tab3[MAX];

int main()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        *(tab3 + i) = *(tab1 + i) + *(tab2 + (MAX -1 ) - i);
    }
}