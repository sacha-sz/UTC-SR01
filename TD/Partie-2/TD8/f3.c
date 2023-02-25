#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int stat;

    if (pid == 0) {
      // sleep(2); // attends que le père se finisse et va donc avoir un ppid de 1
      printf("Ici le fils, mon pid est %ld, le pid de mon père %ld.\n", getpid(), getppid());
      exit(10);
    }
    else {
      //sleep(1); // évite l'erreur et attends une seconde
      wait(&stat); // évite dans tous les cas l'erreur et attends que le processsus fils se finisse
      printf("Ici le parent, mon pid est %ld, le retour du fils est %ld\n", getpid(), WEXITSTATUS(stat));
    }

    return 0;
}
