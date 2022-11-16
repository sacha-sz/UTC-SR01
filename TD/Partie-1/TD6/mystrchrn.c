#include "mystrchrn.h"

int mystrchrn(char *s, char c) {
  char *p;
  int i, n;
  p=s;

  n=0;
  while(*p != '\0')
     {
  	if (*p==c) n++;
   	p++;
     }

  return(n);
}
