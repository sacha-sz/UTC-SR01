#include <unistd.h>
#define STDOUT 1
#define STDIN 0

void fonc_pere();
void fonc_fils();
int f;
int fd[2];

int main() {
	int i;
	pipe(fd);
	f = fork();

	switch (f) {
		case -1 :
			printf("Erreur")
			exit(0);
		case 0 :
			fonc_fils();
			break;
		default:
			fonc_pere();
			break;
	}
}

void fonc_pere() {
	close(STDIN);
	dup(fd[0]);
	close(fd[1]);
	wait(f);
	execlp("wc", "wc", "-l", 0)
}
void fonc_fils() {
	close(STDOUT);
	dup(fd[1]);
	execlp("ls", "ls", "-la", 0)
}
