#include "EX3.h"
#include "stdio.h"
#include "string.h"

#define REP_MAX 6
#define MAX_RESTAURANT 100

int main()
{
    /// Déclaration des variables
    Restaurant restaurants[MAX_RESTAURANT];
    int answer = 0;
    int nb_restaurants;
    int fichier_ouvert = 0;


    /// Interface utilisateur
    while(answer != REP_MAX)
    {
        affiche_menu();
        scanf("%d", &answer);

        switch(answer)
        {
        case 1:
            printf("\n\n********** Ouverture du fichier **********\n\n");
            if (fichier_ouvert == 0)
            {
                nb_restaurants = lire_restaurant(CheminFichier, restaurants);
                printf("Nombre de restaurants dans le fichier : %d\n\n", nb_restaurants);
                fichier_ouvert = 1;
            }
            else
            {
                printf("Le fichier est deja ouvert\n\n");
            }
            break;

        case 2:
            printf("\n\n********** Affichage des restaurants **********\n\n");
            if (fichier_ouvert == 1)
            {
                affiche_restaurant(restaurants, nb_restaurants);
            }
            else
            {
                printf("Le fichier n'est pas ouvert\n");
            }
            break;

        case 3:
            printf("\n\n********** Ajout d'un restaurant **********\n\n");


            /// Initialisation des variables du restaurant rentré par l'utilisateur
            Restaurant restaurant;
            char nom_restaurant[MAX_MOT];
            char adresse_restaurant[MAX_ADRESSE];
            char specialite[MAX_MOT];
            char nom_rue[MAX_MOT];
            char nom_ville[MAX_MOT];
            char numero_rue[MAX_MOT];
            double position_restaurant[2];


            /// Récupération des informations du restaurant
            while(getchar() != '\n');
            printf("Entrez le nom du restaurant a inserer :\n");
            scanf("%[^\n]s", nom_restaurant);
            while(getchar() != '\n');

            printf("Quel est le nom de la rue ?\n");
            scanf("%[^\n]s", nom_rue);
            while(getchar() != '\n');

            printf("Quel est le numero de la rue ?\n");
            scanf("%s", numero_rue);
            while(getchar() != '\n');

            printf("Quel est le nom de la ville ?\n");
            scanf("%[^\n]s", nom_ville);
            while(getchar() != '\n');

            printf("Entrez la position X du restaurant a inserer :\n");
            scanf("%lf", &position_restaurant[0]);

            printf("Entrez la position Y du restaurant a inserer :\n");
            scanf("%lf", &position_restaurant[1]);


            /// Récupération des spécialités
            char nom_specialite_1[MAX_MOT];
            printf("Entrez la premiere specialite du restaurant a inserer :\n");
            scanf("%s", nom_specialite_1);
            restaurant.specialite = creer_specialite(nom_specialite_1);

            int continuer = 1;
            while (continuer == 1)
            {
                printf("Voulez-vous ajouter une autre specialite ? (1 = oui, 0 = non)\n");
                scanf("%d", &continuer);

                if (continuer == 1)
                {
                    printf("Entrez la specialite du restaurant a inserer :\n");
                    scanf("%s", nom_specialite_1);
                    ajout_specialite(restaurant.specialite, nom_specialite_1);
                }
            }

            /// Affection des variables du restaurant

            /// Concaténation de l'adresse
            char * adresse_line = strcat(numero_rue, ", ");
            adresse_line = strcat(adresse_line, nom_rue);
            adresse_line = strcat(adresse_line, " - ");
            adresse_line = strcat(adresse_line, nom_ville);

            for (int i = 0; i < strlen(adresse_line); i++)
            {
                adresse_restaurant[i] = adresse_line[i];
            }

            strcpy(restaurant.nom_restaurant, nom_restaurant);
            strcpy(restaurant.adresse_restaurant, adresse_restaurant);
            restaurant.position_restaurant[0] = position_restaurant[0];
            restaurant.position_restaurant[1] = position_restaurant[1];

            /// Ajout du restaurant
            inserer_restaurant(restaurant);
            break;

        case 4:
            printf("\n\n********** Recherche d'un restaurant **********\n\n");
            if (fichier_ouvert == 1)
            {

                /// Initialisation des variables
                double position_x;
                double position_y;
                double rayon;

                int nb_result;

                /// Récupération des informations
                printf("Entrez votre position X :\n");
                scanf("%lf", &position_x);

                printf("Entrez votre position Y :\n");
                scanf("%lf", &position_y);

                printf("Entrez le rayon de recherche :\n");
                scanf("%lf", &rayon);

                /// Recherche des restaurants
                Restaurant results[MAX_RESTAURANT];
                nb_result = cherche_restaurant(position_x, position_y, rayon, results, restaurants, nb_restaurants);
                if (nb_result == 0)
                {
                    printf("Aucun restaurant trouve\n");
                }
                else
                {
                    affiche_restaurant_distance(results, nb_result);
                }
            }
            else
            {
                printf("Le fichier n'est pas ouvert\n");
            }
            break;

        case 5:

            printf("\n\n********** Recherche d'un restaurant par specialite **********\n\n");

            if (fichier_ouvert == 1)
            {
                /// Initialisation des variables
                Specialite *list_specialite;
                int continuer_r = 1;
                int nb_specialite = 0;

                /// Récupération de toutes les spécialités
                while (continuer_r == 1)
                {
                    char spec_rec[MAX_MOT];
                    while(getchar() != '\n');
                    printf("Entrez la specialite a rechercher :\n");
                    scanf("%[^\n]s", spec_rec);
                    while(getchar() != '\n');

                    if (nb_specialite == 0)
                    {
                        list_specialite = creer_specialite(spec_rec);
                    }
                    else
                    {
                        ajout_specialite(list_specialite, spec_rec);
                    }

                    printf("Voulez-vous ajouter une autre specialite ? (1 : Oui, 0 : Non)\n");
                    scanf("%d", &continuer_r);
                    nb_specialite++;
                }

                /// Recherche des restaurants par distance et par spécialité

                /// Initialisation des variables de la position
                double position_x2;
                double position_y2;
                int nb_result2;

                printf("\nEntrez votre position X :\n");
                scanf("%lf", &position_x2);

                printf("Entrez votre position Y :\n");
                scanf("%lf", &position_y2);


                /// Recherche des restaurants
                Restaurant results2[MAX_RESTAURANT];
                nb_result2 = cherche_par_specialite(position_x2, position_y2, list_specialite, results2, restaurants,
                                       nb_restaurants);

               if (nb_result2 > 1)
               {
                   affiche_restaurant_distance(results2, nb_result2);
               }
               else
               {
                   printf("Aucun restaurant ne correspond a votre recherche\n");
               }
            }
            else
            {
                printf("Le fichier n'est pas ouvert\n");
            }
            break;

        case REP_MAX:
            printf("\n\n********** Fermeture du programme **********\n\n");

            if (fichier_ouvert == 1)
            {
                liberer_restaurant(restaurants, nb_restaurants);
            }

            printf("Au revoir !\n");
            break;


        default:
            printf("\n\n********** Erreur **********\n\n");
            printf("Choix invalide\n\n");
            break;
        }
    }

    return 0;
}
