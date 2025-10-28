#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

int main(){
    debut:

    int choix;

    choix = menu();

    switch (choix)
    {
    case 1:
        /* code */
        break;
    case 6:
    loadCandidat();
    printf("Verification des candidatures\n");
        checkCandidat();
        break;
    
    default:
        goto debut;
        break;
    }
    return 0;
    
}