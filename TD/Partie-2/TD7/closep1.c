#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd,fd2;

    fd = open("toto.txt",O_RDWR|O_CREAT,0666); // Ajout à la première case disponible
    // O_RDWR : autorise écriture lecture
    // O_CREATE : si non existant alors créé
    // 0666 : droit utilisateur

    printf( "avant close\n");
    close(1); // ferme le disquéteur 1 : stdout

    printf("apres close\n");
    dup (fd); // Duplique le disquéteur dans la première case disponible

    printf("apres dup\n");
    close(fd); // On ferme fd

    close(1);
    fd = open("/dev/tty", O_RDWR, 0666);
    printf("Le 4eme printf...\n");

    return 0;
}
