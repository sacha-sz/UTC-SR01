#ifndef EX3_H
#define EX3_H

#define MAX_MOT 40
#define MAX_ADRESSE 100
#define CheminFichier "restau.txt" // A remplacer par votre chemin d'accés


typedef struct Specialite {
    char nom_specialite[MAX_MOT];
    struct Specialite *suivant;
} Specialite;

typedef struct Restaurant {
    char nom_restaurant[MAX_MOT];
    char adresse_restaurant[MAX_ADRESSE];
    Specialite * specialite;
    double position_restaurant [2];
} Restaurant;

Specialite *creer_specialite(char nom_specialite[MAX_MOT]);


int est_present(Specialite *spec, char *nom_specialite);
int lire_restaurant (char* chemin, Restaurant restaurants []);
int cherche_restaurant(double x, double y, double rayon_recherche, Restaurant *results, Restaurant restaurants[], int nb_restaurants);
int cherche_par_specialite(double x, double y, Specialite *spec, Restaurant *results, Restaurant restaurants[], int nb_restaurants);


void inserer_restaurant(Restaurant restaurant);
void liberer_restaurant (Restaurant restaurants [], int nb_restaurants);
void affiche_restaurant (Restaurant restaurants [], int nb_restaurants);
void affiche_menu();
void tri_restaurant(Restaurant *results, int nb_restaurants);
void ajout_specialite(Specialite *specialite, char nom_specialite[MAX_MOT]);
void affiche_specialite(Specialite *specialite);
void liberer_specialite(Specialite *specialite);
void affiche_restaurant_distance (Restaurant restaurants [], int nb_restaurants);


double calcul_distance(double x1, double y1, double x2, double y2);

#endif //EX3_H
