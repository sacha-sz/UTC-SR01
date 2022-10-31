#include "EX2.h"
#include "stdio.h"
#include "stdlib.h"


int main() {
    int* points = lectureNotes();
    statsNotes(points);
    affichagePoints(points);
    affichageBarres(points);
    free(points);

    return 0;
}
