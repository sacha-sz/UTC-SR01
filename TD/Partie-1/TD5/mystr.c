#include <stdio.h>
#include <stdlib.h>
#include "string.h"


void mystrupdown(char *s1, char *s2)
{
    for (int i = 0; i < strlen(s1); i++)
    {

        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s2[i]=(s1[i]-'a')+'A';
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s2[i]=(s1[i]-'A')+'a';
        }
        else
        {
            s2[i] = s1[i];
        }
    }
}

void mystrinv(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        s2[i] = s1[strlen(s1) - i - 1];
    }
}

int mystrchrn(char *s, char c)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
            count++;
    }

    return count;
}

void mystrncpy(char *s1, char *s2, int n)
{
    int nb = n > strlen(s2) ? strlen(s1) : n;
    int pos_init = strlen(s1) - nb -1;

    for (int i = 0; i < nb; i++)
    {
        s2[i] = s1[i + pos_init];
    }
}

void mystrncat(char *s1, char *s2, int n)
{
    int nb = n > strlen(s2) ? strlen(s1) : n;

    strcat(s2, s1 + strlen(s1) - nb);
}