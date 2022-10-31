#ifndef TD2_SR01_EX4_H
#define TD2_SR01_EX4_H

typedef struct complexe{
    float x;
    float y;
} Complexe;

union valeur{
    int entier;
    float reel;
    struct complexe complexe;
};

enum genre {entier, reel, complexe};

typedef struct nombre{
    enum genre  type;
    union valeur valeur;
}nombre ;

nombre saisir_nombre();
void afficher_nombre(nombre);

void Affiche_c (Complexe c);
Complexe multiplication (Complexe c1, Complexe c2);
Complexe somme (Complexe c1, Complexe c2);

#endif //TD2_SR01_EX4_H