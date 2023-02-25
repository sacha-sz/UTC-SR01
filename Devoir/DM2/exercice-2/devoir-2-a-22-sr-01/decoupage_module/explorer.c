#include "explorer.h"

void explorer(int debut, int fin){
  int etat,pid,pid2;
  int nb_fils = 0;
  pid=fork();
  if(pid==0){
    for (int i=debut; i<=fin;i++){
      if (premier(i)==1) {
        pid2=fork();
        fflush(stdout);
        if (pid2==0){
          char chaine[250];
          sprintf(chaine,"echo '%d  est un nombre premier\
          PID du processus qui a appelé system() : %d\
          PID de son père (qui exécute la boucle for) : %d\
          PID du processus qui écrit le message : '$$>>nbr_premiers.txt",
          i,getpid(), getppid());
          if (my_system(chaine) == EXIT_FAILURE)
            perror("my_system");
          sleep(2);
          exit(0);
        }
        else /* wait(&etat);// instruction 41*/
          // En commentant cette instruction nous permettons aux processus fils de se lancer en parallèle
          // Nous gardons cependant une trace du nombre de processus fils
          nb_fils++;
      }
    }

    // A l'aide du nombre de nos processus fils, nous pouvons maintenant tous les récupérer et ainsi éviter les processus zombies
    int nb_fils_termines = 0;
    while (nb_fils_termines < nb_fils) {
        int pid = waitpid(-1, &etat, WNOHANG);
        if (pid > 0) {
          // Traitement du processus fils terminé
          printf("Un processus fils a terminé (PID = %d)\n", pid); // Affichage permettant de nous assurer que les processus fils sont bien récupérés
          nb_fils_termines++;
        }
    }

    exit(0);
  } else wait(&etat); // instruction 46
}