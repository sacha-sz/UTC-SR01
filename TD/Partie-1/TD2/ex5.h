#ifndef TD2_SR01_EX5_H
#define TD2_SR01_EX5_H

#define NBRE_ETUDIANTS

struct Etudiant
{
    char  nom[20];
    char  prenom[20];
    char n_compte[7];
};

void affiche_etu (struct Etudiant etu);
struct Etudiant Saisir_etudiant();
struct Etudiant* creer_etu (char * nom, char * prenom, char * n_compte);
#endif //TD2_SR01_EX5_H
