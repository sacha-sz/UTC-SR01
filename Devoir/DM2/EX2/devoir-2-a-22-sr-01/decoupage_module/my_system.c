#include "my_system.h"

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