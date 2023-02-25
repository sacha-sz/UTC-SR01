#include "premier.h"

int premier(int nb) {
    int r=0;
    
    for(int i = 1 ; i <= nb ; i++ ) {
        if(nb % i == 0) r++;
    }
    
    if(r>2)
       return 0;
    else
       return 1;
}
   