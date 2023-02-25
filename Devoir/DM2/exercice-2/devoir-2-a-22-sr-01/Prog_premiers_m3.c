#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
int premier(int nb)
{
    int r=0;

    for(int i = 1 ; i <= nb ; i++ )
    {
        if(nb % i == 0)
        {
           r++;
        }
    }

    if(r>2)
       return 0;
    else
       return 1;

}

int my_system(char * ma_chaine){
  int pid, etat;
  char * arg [] =  {"/bin/bash", "-c", ma_chaine, NULL};

  switch(pid=fork()) {
    case  0 :
      // Nous sommes dans le processus fils :
      // Nous exécutons la commande execv qui va recouvrir la suite du code
      execv(arg[0], arg);

      // N'est exécuter que si execv a échoué
      perror("my_system/execv");
      return EXIT_FAILURE;

    case -1 :
      // Le fork de la fonction my_system a échoué
      perror("my_system/fork");
      return EXIT_FAILURE;

    default :
      // Le processus père attends la fin du processus fils (qui exécute execv)
      wait(&etat);
      break;
  }

  return EXIT_SUCCESS;
}

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


int main(){
  int grp=1;
  while(grp<=11){
    explorer(grp+1,grp+10);
    grp=grp+10;

  }
}
