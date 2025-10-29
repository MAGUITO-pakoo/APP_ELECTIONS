#include "../include/util.h"
#include "../include/electeurs.h"
#include "../include/candidats.h"

int main(){
    debut:

    int choix;
    clearScreen();

    choix = menu();

    switch (choix)
    {
    case 1:
        loadCandidat();
        printf(GRAS);
        annoncerCandidats();
        printf(RESET);
        break;
    case 2:
        printf("Ajouter un candidat\n");
        break;
    case 3:
        loadCandidat();
        printf(GRAS "==== Verification des candidatures ====\n" RESET);
        checkCandidat();
        break;
    case 4:
        getchar();
        printf(GRAS "\n==== ENREGISTREMENT D'UN ELECTEUR ====\n" RESET);
        enregistrerElecteur();
        break;
    case 5:
        printf("Liste d'electeurs\n");
        break;
    case 6:
        loadCandidat();
        printf("Simulation de Vote\n");
        break;
    case 99:
        printf(CYAN GRAS"Fin du Programme\n" RESET);
        goto fin;
    
    default:
        goto debut;
        break;
    }
    fin:
    return 0;
    
}