#include "EX2.h"
#include "stdio.h"
#include "stdlib.h"


// On lit N notes
int* lectureNotes() {
    int* points = malloc(N * sizeof(int));
    int i;
    for (i = 0; i < N; i++) {
        do {
            printf("Entrez la note de l'étudiant %d: ", i + 1);
            scanf("%d", &points[i]);
            if (points[i] < 0 || points[i] > 60) {
                printf("La note doit être comprise entre 0 et 60.\n");
            }
        } while (points[i] < 0 || points[i] > 60);
    }
    return points;
}


// On calcule les statistiques
void statsNotes(int points[N]) {
    int i;
    int max = points[0];
    int min = points[0];
    int somme = 0;
    for (i = 0; i < N; i++) {
        if (points[i] > max) {
            max = points[i];
        }
        if (points[i] < min) {
            min = points[i];
        }
        somme += points[i];
    }
    printf("La note maximale est %d, la note minimale est %d, la moyenne est %f.\n", max, min, (float) somme / N);
}


// On compte les notes par tranche de 10 (on range les notes supérieures à 60 dans la dernière tranche)
int* notes_tab(int points[N]){
    int* notes = malloc(7 * sizeof(int));
    int i;
    for (i = 0; i < 7; i++) {
        notes[i] = 0;
    }
    for (i = 0; i < N; i++) {
        if (points[i] == 60) {
            notes[6]++;
        } else if (points[i] >= 50) {
            notes[5]++;
        } else if (points[i] >= 40) {
            notes[4]++;
        } else if (points[i] >= 30) {
            notes[3]++;
        } else if (points[i] >= 20) {
            notes[2]++;
        } else if (points[i] >= 10) {
            notes[1]++;
        } else {
            notes[0]++;
        }
    }
    return notes;
}


void affichagePoints(int points[N]) {
    int* tab_notes = notes_tab(points);
    int max = tab_notes[0];
    for (int i = 0; i < 7; i++) {
        if (tab_notes[i] > max) {
            max = tab_notes[i];
        }
    }
    for (int i = max; i > 0; i--) {
        printf("%2.d >  ", i);
        for (int j = 0; j < 7; j++) {
            if (tab_notes[j] == i) {
                printf("    o   ");
            } else {
                printf("        ");
            }
        }
        printf("\n");
    }
    printf("      ");
    for (int j = 0; j < 7; j++) {
        if (tab_notes[j] == 0) {
            printf("+---o---");
        } else {
            printf("+-------");
        }
    }
    printf("+\n      ");
    for (int j = 0; j < 6; j++) {
        printf("| %-2.1d-%2.d ", j * 10, (j + 1) * 10 - 1);
    }
    printf("|  %d+  |\n\n", 60);
}


void affichageBarres(int points[N]) {
    int* tab_notes = notes_tab(points);
    int max = tab_notes[0];
    for (int i = 0; i < 7; i++) {
        if (tab_notes[i] > max) {
            max = tab_notes[i];
        }
    }
    for (int i = max; i > 0; i--) {
        printf("%2.d >  ", i);
        for (int j = 0; j < 7; j++) {
            if (tab_notes[j] >= i) {
                printf(" #######");
            } else {
                printf("        ");
            }
        }
        printf("\n");
    }
    printf("      ");
    for (int j = 0; j < 7; j++) {
        printf("+-------");
    }
    printf("+\n      ");
    for (int j = 0; j < 6; j++) {
        printf("| %-2.1d-%2.d ", j * 10, (j + 1) * 10 - 1);
    }
    printf("|  %d+  |\n\n", 60);
}
