#include "EX3.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define MAX_LIGNE 1000


int lire_restaurant (char* chemin, Restaurant restaurants [])
{
    if (chemin == NULL || restaurants == NULL)
    {
        return -1;
    }


    FILE* input_file = fopen(chemin, "r");

    if (input_file == NULL)
    {
        // Si le fichier n'a pas pu être ouvert
        printf("Erreur: le fichier %s n'a pas pu etre ouvert\n", chemin);
        return -1;
    }

    // Initialisation des variables
    char ligne[MAX_LIGNE];

    // Initialisation de la constante de séparation des mots
    const char * sep = ";";
    const char * sep2 = ",";
    int nb_restaurants = 0;
    int type= 0; // 0 = nom, 1 = adresse, 2 = position, 3 = specialite

    fgets(ligne, MAX_LIGNE, input_file); // Saut de la première ligne

    while(fgets(ligne, MAX_LIGNE, input_file) != NULL)
    {
        if (ligne[0] == '\n')
        {
            // On passe les lignes vides
            continue;
        }

        if (ligne[strlen(ligne) - 1] == '\n')
        {
            // On enlève le \n à la fin de la ligne
            ligne[strlen(ligne) - 1] = '\0';
        }

        if (ligne[strlen(ligne) - 1] == ';')
        {
            // On enlève le dernier ;
            ligne[strlen(ligne) - 1] = '\0';
        }
        type = 0;

        char *mot = strtok(ligne, sep);
        char *mot_next;


        while(mot != NULL)
        {
            while (mot[0] == ' ')
            {
                // On enlève l'espace au début du mot
                mot = mot + 1;
            }

            if (type == 0)
            {
                // On ajoute le nom du restaurant
                strcpy(restaurants[nb_restaurants].nom_restaurant, mot);
            }
            else if (type == 1)
            {
                // On ajoute l'adresse du restaurant
                strcpy(restaurants[nb_restaurants].adresse_restaurant, mot);
            }
            else if (type == 2)
            {
                mot_next = strtok(NULL, sep);

                // On ajoute la position du restaurant
                char *mot2 = strtok(mot, sep2);

                mot2 = mot2 + 3; // On enlève les 3 premiers caractères : (x=
                restaurants[nb_restaurants].position_restaurant[0] = atof(mot2);

                mot2 = strtok(NULL, sep2);
                mot2 = mot2 + 3; // On enlève les 3 premiers caractères : y=
                mot2[strlen(mot2) - 1] = '\0'; // On enlève le dernier caractère : )

                restaurants[nb_restaurants].position_restaurant[1] = atof(mot2);

            }
            else if (type == 3)
            {
                // On enlève le premier caractère : { et le dernier : }
                mot = mot + 1;
                mot[strlen(mot) - 1] = '\0';

                char *mot2 = strtok(mot, sep2);
                int premiere_val = 0;
                while(mot2 != NULL)
                {
                    if (mot2[0] == ' ')
                    {
                        // On enlève l'espace au début du mot
                        mot2 = mot2 + 1;
                    }
                    if (premiere_val == 0)
                    {
                        restaurants[nb_restaurants].specialite = creer_specialite(mot2);
                        premiere_val = 1;
                    }
                    else
                    {
                        ajout_specialite(restaurants[nb_restaurants].specialite, mot2);
                    }
                    mot2 = strtok(NULL, sep2);
                }
            }


            if (type==2)
            {
                mot = mot_next;
            }
            else
            {
                mot = strtok(NULL, sep);
            }

            type++; // On passe au type suivant
        }
        nb_restaurants++;
    }

    fclose(input_file);  // On ferme le fichier
    return nb_restaurants;
}

void liberer_restaurant (Restaurant restaurants [], int nb_restaurants)
{
    if (restaurants == NULL || nb_restaurants <= 0)
    {
        return;
    }
    /// Suppression des restaurants
    for (int i = 0; i < nb_restaurants; i++)
    {
        printf("Suppression du restaurant %s\n", restaurants[i].nom_restaurant);
        liberer_specialite(restaurants[i].specialite);
    }
}

void affiche_restaurant (Restaurant restaurants [], int nb_restaurants)
{
    for (int i = 0; i < nb_restaurants; i++)
    {
        printf("Restaurant : %s\n", restaurants[i].nom_restaurant);
        printf("\tAdresse : %s\n", restaurants[i].adresse_restaurant);
        printf("\tPosition : %+lf, %+lf\n", restaurants[i].position_restaurant[0], restaurants[i].position_restaurant[1]);
        affiche_specialite(restaurants[i].specialite);
    }
}


void inserer_restaurant(Restaurant restaurant)
{
    FILE* output_file = fopen(CheminFichier, "a");

    if (output_file == NULL)
    {
        // Si le fichier n'a pas pu être ouvert
        printf("Erreur: le fichier restaurants.txt n'a pas pu etre ouvert\n");
        return;
    }

    fprintf(output_file, "\n\n%s; %s;(x=%lf, y=%lf); {", restaurant.nom_restaurant, restaurant.adresse_restaurant, restaurant.position_restaurant[0], restaurant.position_restaurant[1]);
    Specialite *specialite = restaurant.specialite;
    while(specialite != NULL)
    {
        if (specialite->suivant == NULL)
        {
            fprintf(output_file, "%s", specialite->nom_specialite);
        }
        else
        {
            fprintf(output_file, "%s, ", specialite->nom_specialite);
        }
        specialite = specialite->suivant;
    }
    fprintf(output_file, "};\n\n");

    fclose(output_file);
}


void affiche_menu()
{
    printf("********** Menu **********\n");
    printf("1. Lecture restaurant fichier\n");
    printf("2. Affichage restaurant\n");
    printf("3. Ajout restaurant au fichier\n");
    printf("4. Recherche restaurants autour de moi\n");
    printf("5. Recherche restaurants par specialite\n");
    printf("6. Liberation de la memoire et quitter\n");
    printf("Saisir votre choix : ");
}

int cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[], Restaurant restaurants[], int nb_restaurants)
{
    if (restaurants == NULL || nb_restaurants <= 0 || results == NULL || rayon_recherche <= 0)
    {
        return 0;
    }

    /// Lecture des restaurants et ajout dans le tableau results si le restaurant est dans le rayon de recherche
    int nb_results = 0;
    for (int i = 0; i < nb_restaurants; i++)
    {
        if (calcul_distance(x, y, restaurants[i].position_restaurant[0], restaurants[i].position_restaurant[1]) <= rayon_recherche)
        {
            results[nb_results] = restaurants[i];
            nb_results++;
        }
    }

    if (nb_results > 1)
    {
        /// Tri des résultats par distance croissante
        tri_restaurant(results, nb_results);
    }

    return nb_results;
}

double calcul_distance(double x1, double y1, double x2, double y2)
{
    /// Calcul de la distance entre deux points
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


int cherche_par_specialite(double x, double y, Specialite *spec, Restaurant *results, Restaurant restaurants[], int nb_restaurants)
{
    if (restaurants == NULL || nb_restaurants <= 0 || results == NULL || spec == NULL)
    {
        return 0;
    }

    int pos =0;
    for (int i =0; i < nb_restaurants; i++) {
        Specialite *temp = restaurants[i].specialite;

        while (temp != NULL) {
            if (est_present(spec, temp->nom_specialite)) {
                results[pos] = restaurants[i];
                pos++;
                break;
            }

            temp = temp->suivant;
        }

    }

    /// Tri des résultats par distance
    if (pos > 1)
    {
        tri_restaurant(results, pos);
    }
    return pos;
}

int est_present(Specialite *spec, char *nom_specialite)
{
    if (spec == NULL || nom_specialite == NULL)
    {
        return 0;
    }

    Specialite *temp = spec;

    while(temp != NULL)
    {
        if (strcmp(temp->nom_specialite, nom_specialite) == 0)
        {
            return 1;
        }
        temp = temp->suivant;
    }

    return 0;
}


void tri_restaurant(Restaurant *results, int nb_restaurants)
{
    if (results == NULL || nb_restaurants <= 0)
    {
        return;
    }

    Restaurant temp;

    /// Tri par insertion
    for (int i = 0; i < nb_restaurants; i++)
    {
        for (int j = i + 1; j < nb_restaurants; j++)
        {
            if (calcul_distance(0, 0, results[i].position_restaurant[0], results[i].position_restaurant[1]) > calcul_distance(0, 0, results[j].position_restaurant[0], results[j].position_restaurant[1]))
            {
                temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }
}


Specialite *creer_specialite(char nom_specialite[MAX_MOT])
{
    if (nom_specialite == NULL)
    {
        return NULL;
    }

    Specialite *new;
    new = malloc(sizeof(Specialite));
    if (new == NULL)
    {
        printf("Erreur: impossible d'allouer de la memoire\n");
        return NULL;
    }
    strcpy(new->nom_specialite, nom_specialite);
    new->suivant = NULL;
    return new;
}

void ajout_specialite(Specialite *specialite, char nom_specialite[MAX_MOT])
{
    if (specialite == NULL || nom_specialite == NULL)
    {
        return;
    }

    Specialite *new;
    new = creer_specialite(nom_specialite);
    if (new == NULL)
    {
        printf("Erreur: impossible d'allouer de la memoire\n");
        return;
    }

    while (specialite->suivant != NULL)
    {
        specialite = specialite->suivant;
    }

    specialite->suivant = new;
}

void affiche_specialite(Specialite *specialite)
{
    if (specialite == NULL)
    {
        return;
    }

    printf("\tSpecialite :\n");
    while (specialite != NULL)
    {
        printf("\t\t%s\n", specialite->nom_specialite);
        specialite = specialite->suivant;
    }
}

void liberer_specialite(Specialite *specialite)
{
    if (specialite == NULL)
    {
        return;
    }

    /// Libération de la mémoire allouée pour les spécialités
    Specialite *temp;
    while (specialite != NULL)
    {
        temp = specialite;
        specialite = specialite->suivant;
        free(temp);
    }
}

void affiche_restaurant_distance (Restaurant restaurants [], int nb_restaurants)
{
    for (int i = 0; i < nb_restaurants; i++)
    {
        printf("Restaurant : %s\n", restaurants[i].nom_restaurant);
        printf("Distance : %lf\n", calcul_distance(0, 0, restaurants[i].position_restaurant[0], restaurants[i].position_restaurant[1]));
        printf("\tAdresse : %s\n", restaurants[i].adresse_restaurant);
        printf("\tPosition : %+lf, %+lf\n", restaurants[i].position_restaurant[0], restaurants[i].position_restaurant[1]);
        affiche_specialite(restaurants[i].specialite);
    }
}
