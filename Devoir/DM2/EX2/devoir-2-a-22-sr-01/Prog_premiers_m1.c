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


void explorer(int debut, int fin){
  int etat,pid,pid2;
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
          i, getpid(), getppid());
          // On récupère le PID du processus à l'aide de la commande shell $$

          system(chaine);
          sleep(2);
          exit(0);
        }
        else wait(&etat);// instruction 41
      }
      
    }
    exit(0);    
  } else wait(&etat);// instruction 46
}


int main(){ 
  int grp=1; 
  while(grp<=11){
    explorer(grp+1,grp+10);
    grp=grp+10;
    
  } 
}
