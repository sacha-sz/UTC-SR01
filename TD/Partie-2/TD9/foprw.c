#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 80

int main(){
  char buf[4]="xxx\n";
  int n;
  char c;


  FILE * fout, * fin;

  fout = fopen("fop.in","r");
  if (fout==NULL) {
    perror("fop erreur :");
    exit(0);
  }


  fin = fopen("fop.out","w+");
  if (fin==NULL) {
    perror("fop erreur :");
    exit(0);
  }

  while(!feof(fin)) {
    n = fread(&c, 1, 11 fin);
    if (n==1) {
      if (c != '\n')
        n = fwrite(&c, 1, 1, fout);
      else
        n = fwrite(buf, 1, 4, fout);
    }
  }


  fclose(fin);
  fclose(fout);
  return 0;
}
