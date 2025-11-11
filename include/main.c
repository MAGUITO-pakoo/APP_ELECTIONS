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
    case 7:
         loadElecteur();
        char checkNom[50];
        char checkprenom[50];
        printf("\nEntrez le nom de l'electeur à verifier \n");
        scanf("%s", checkNom); 
        printf("\nEntrez le prenom de l'electeur à verifier \n");
        scanf("%s", checkprenom);
        int checkVote = aVote(electeurs, countElecteur, checkNom, checkprenom);

        switch (checkVote)
        {
        case 1:
            printf("Cet electeur a bien voté");
            break;
        case 0:
            printf("Cet electeur n'a pas voté");
            break;
        case -1:
            printf("Cet nom n'a pas été trouvé");
            break;
        }
        break;
    case 8:
        loadElecteur();
        loadCandidat();
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