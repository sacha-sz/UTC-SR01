#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256
#define MAX_PROCESS 20

// Structure qui contient les informations sur une application
typedef struct {
    char name[MAX_LINE_LENGTH];
    char path[MAX_LINE_LENGTH];
    int num_arguments;
    char **arguments;
} application;

// Variables globales
pid_t pid_power_manager;
pid_t pid_running_process[MAX_PROCESS];
int num_running_process = 0;
application **applications;
int num_applications = 0;

// Prototypes des fonctions
void my_system(int indice);
void parse(char *filename);
void affichage();
void add_running_process(pid_t pid);
void remove_running_process(pid_t pid);
void app_manager();
void veille_handler(int signum, siginfo_t *info, void *ptr);


void my_system(int indice){
    // Cette fonction sert a lancer une application en gerant les differents cas
    // elle ne cree pas de processus fils et fait juste des appels a execv ou execl

    if (applications[indice]->num_arguments == 0) {
        execl(applications[indice]->path, applications[indice]->name, NULL);
    }
    else {
        char *arguments[applications[indice]->num_arguments + 2];
        arguments[0] = applications[indice]->name;
        for (int i = 0; i < applications[indice]->num_arguments; i++) {
            arguments[i + 1] = applications[indice]->arguments[i];
        }
        arguments[applications[indice]->num_arguments + 1] = NULL;
        execv(applications[indice]->path, arguments);
    }
}

// Fonction qui lit le fichier de configuration et stocke les informations dans le tableau applications
void parse(char *filename){
    char line[MAX_LINE_LENGTH];
    unsigned int length;

    // Ouvre le fichier en lecture
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    // Lit le nombre d'applications
    fgets(line, MAX_LINE_LENGTH, fp);
    sscanf(line, "nombre_applications=%d", &num_applications);

    // Alloue un tableau de structures de la bonne taille
    applications = malloc(num_applications * sizeof(application*));
    if (applications == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de memoire\n");
        exit(1);
    }

    // Lit les informations sur chaque application et les stock dans le tableau
    for (int i = 0; i < num_applications; i++) {

        applications[i] = malloc(sizeof(application));
        if (applications[i] == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation de memoire\n");
            exit(1);
        }
        
        // Lit le nom de l'application
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "name=%[^\n]", applications[i]->name);
        
        // Lit le chemin de l'application
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "path=%[^\n]", applications[i]->path);

        // Lit le nombre d'arguments de l'application
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "nombre_arguments=%d", &applications[i]->num_arguments);

        // Alloue un tableau de chaines de caracteres pour stocker les arguments
        applications[i]->arguments = malloc(applications[i]->num_arguments * sizeof(char*));
        if (applications[i]->arguments == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation de memoire\n");
            exit(1);
        }

        // Lit la ligne "arguments=" pour passer ensuite aux arguments
        fgets(line, MAX_LINE_LENGTH, fp);

        // Lit les arguments de l'application
        for (int j = 0; j < applications[i]->num_arguments; j++) {
            fgets(line, MAX_LINE_LENGTH, fp);
            applications[i]->arguments[j] = strdup(line);
            length = strlen(applications[i]->arguments[j]);
            if (applications[i]->arguments[j][length - 1] == '\n') {
                applications[i]->arguments[j][length - 1] = '\0';
            }
        }

        // Lit la ligne vide qui suit les arguments
        fgets(line, MAX_LINE_LENGTH, fp);
    }

    // Ferme le fichier
    fclose(fp);
}

void affichage(){
    // Affiche les informations sur chaque application
    printf("\n========================================================================\n\n");
    printf("***Affichage des informations sur les applications***\n\n");
    printf("Nombre d'applications: %d\n\n", num_applications);
    for (int i = 0; i < num_applications; i++) {
        printf("Nom de l'application: %s\n", applications[i]->name);
        printf("Chemin de l'application: %s\n", applications[i]->path);
        printf("Nombre d'arguments: %d\n", applications[i]->num_arguments);
        printf("Arguments: ");
        
        for (int j = 0; j < applications[i]->num_arguments; j++) {
            printf("%s ", applications[i]->arguments[j]);
        }
        printf("\n\n");
    }
    printf("========================================================================\n\n");
}

// Fonction qui ajoute un processus a la liste des processus en cours d'execution
void add_running_process(pid_t pid){
    pid_running_process[num_running_process] = pid;
    num_running_process++;
}

// Fonction qui retire un processus de la liste des processus en cours d'execution
void remove_running_process(pid_t pid){
    for (int i = 0; i < num_running_process; i++) {
        if (pid_running_process[i] == pid) {
            printf("\nL'application \"%s\" s'est terminee.\n\n", applications[i]->name);

            // On libere la memoire
            free(applications[i]->arguments);
            free(applications[i]);

            // On retire l'application de la liste des processus en cours d'execution et des programmes
            for (int j = i; j < num_running_process - 1; j++) {
                pid_running_process[j] = pid_running_process[j + 1];
                applications[j] = applications[j + 1];
            }
            num_running_process--;
            break;
        }
    }
}

// Fonction qui lance les applications
void app_manager(){
    // Execute les applications et attend leur fin

    for (int i = 0; i < num_applications; i++) {
        pid_t pid_fils = fork();
        if (pid_fils == 0) {
            // Execute l'application, ce code ne sera execute que par le fils

            printf("\nLancement de l'application \"%s\"...\n\n", applications[i]->name);

            my_system(i);
        }
        else{
            sleep(1);

            // On recupere le pid du Power Manager
            if (strcmp(applications[i]->name, "Power Manager") == 0) {
                pid_power_manager = pid_fils;
            }

            add_running_process(pid_fils);
        }
    }
    
    // Attend la fin des applications qui se ferment par elles-memes
    // Celles qui ne se ferment pas par elles-memes sont tuees par le handler de SIGUSR1
    // lorsque ce signal est envoye par le Power Manager
    while (1){
        pid_t pid_fils_termine = wait(0);

        remove_running_process(pid_fils_termine);
    }
}

// handler pour le signal SIGUSR1
void veille_handler(int signum, siginfo_t *info, void *ptr){

    // On recupere le pid de l'emetteur du signal
    pid_t pid_emetteur = info->si_pid;

    // Si le signal est envoye par le Power Manager, on tue tous les processus encore en cours et on quitte
    if (pid_emetteur == pid_power_manager) {
        
        pid_t pid_fils_termine;

        while(num_running_process > 0){
            pid_fils_termine = pid_running_process[0];
            remove_running_process(pid_fils_termine);
            kill(pid_fils_termine, SIGINT);
        }

        // On libere la memoire pour le tableau de pointeurs sur les applications
        free(applications);
        exit(0);
    }
}

int main(int argc, char *argv[]) {

    // On cree un handler pour le signal SIGUSR1
    struct sigaction S;
    S.sa_sigaction = veille_handler;
    sigemptyset(&S.sa_mask);
    S.sa_flags = SA_SIGINFO;
    if( sigaction(SIGUSR1, &S, NULL) != 0 ){
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    parse("list_appli.txt");
    
    affichage();

    app_manager();
    return 0;
}
