#include "mystrinv.h"

void mystrinv(char *s1, char *s2) {
    int size_s1 = 0;
    while (s1[size_s1] != '\0') {
        size_s1++;
    }

    for (int i = 0; s1[i] != '\0'; i++) {
        s2[i] = s1[size_s1 - i - 1];
    }
}