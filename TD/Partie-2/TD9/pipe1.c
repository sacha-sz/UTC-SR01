#include <stdio.h>
#include <fcntl.h>

int main() {
	int tab1[10]={11,22,33,44,55,66,77,88,99,1000};
	int tab2[10];
	int i,fd[2];

	pipe(fd);

	write (fd[1],tab1,10*sizeof(int));
	read (fd[0],tab2,10*sizeof(int));

	close(fd);

	for (i=0;i<10;i++)
		printf("%d,%d\n",tab2[i],tab1[i]);

	return 0;
}
