#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    printf("Mon pid est : %d et le pid de mon père est : %d\n", getpid(), getppid());
    fflush(stdout);
    sleep(1);


    int pid_fils;

    for (int i = 4; i > 0 ; i--) {
        pid_fils = fork();

        if (pid_fils == -1) {
            perror("Erreur fork");
            exit(1);
        }
        else if (pid_fils == 0) {
            sleep(1);
            printf("Mon pid est : %d et le pid de mon père est : %d\n", getpid(), getppid());
            fflush(stdout);
        }
        else  {
            wait(0);
        }
    }

    return 0;
}
