#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid_1 = fork();


    if (pid_1 == 0) {
      // sleep(2); // attends que le père se finisse et va donc avoir un ppid de 1
      printf("Ici le fils, mon pid est %ld, le pid de mon père %ld.\n", getpid(), getppid());
      exit(0);
    }
    else {
      // sleep(1); // évite l'erreur et attends une seconde
      pid_t pid_2 = fork();
      wait(pid_1);
      if (pid_2 == 0) {
        printf("Ici le fils, mon pid est %ld, le pid de mon père %ld.\n", getpid(), getppid());
        exit(0);
      }
       // évite dans tous les cas l'erreur et attends que le processsus fils se finisse
      else {
        wait(pid_2);
        printf("Ici le parent, mon pid est %ld, le pid de mes fils sont : [%ld; %ld]\n", getpid(), pid_1, pid_2);
      }
    }

    return 0;
}
