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
        loadElecteur();
        simulerVote(electeurs, countElecteur, countCandidat);
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
        loadCandidat();
        loadElecteur();
        ResultatVote resultat = compteVote(electeurs, countElecteur, candidats, countCandidat);

        printf("=== Résultats du vote ===\n");
        for (int i = 0; i < resultat.i; i++) {
            printf("%s %s (%s) : %d votes (%f %%) \n",
                resultat.candidat[i].prenom,
                resultat.candidat[i].nom,
                resultat.candidat[i].parti,
                resultat.nbVote[i],
                resultat.pourcent[i]);
    }
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




/* int main() {
     Electeur electeurs[] = {
        {"POKEM", "Dane", 1, 2, "Nkolbisson", 19},
        {"MELI", "Ange", 2, 0, "Biyem-Assi", 21},
        {"ZO'O", "Levi", 3, 1, "Essos", 25},
        {"ABANDA", "Walter", 4, 1, "Mokolo", 22},
        {"M", "Krys", 5, 2, "Ngousso", 20}
    };

    Candidat candidats[] = {
        {"ZOLA", "Emile", 1, "Parti du Soleil", {12, 4, 1975}},
        {"CONNOR", "Sarah", 2, "Parti du Lion", {5, 9, 1980}},
        {"SAINT", "Jonas", 3, "Parti du Progrès", {22, 11, 1978}}
    };

    int tailleE = sizeof(electeurs) / sizeof(electeurs[0]);
    int tailleC = sizeof(candidats) / sizeof(candidats[0]);

    // ✅ Test du décompte des votes
    ResultatVote resultat = compteVote(electeurs, tailleE, candidats, tailleC);

    printf("=== Résultats du vote ===\n");
    for (int i = 0; i < resultat.i; i++) {
        printf("%s %s (%s) : %d votes (%f %%) \n",
               resultat.candidat[i].prenom,
               resultat.candidat[i].nom,
               resultat.candidat[i].parti,
               resultat.nbVote[i],
               resultat.pourcent[i]);
    }

    // ✅ Test de la fonction aVote()
    printf("\nTest de aVote() :\n");
    printf("Dane -> %d\n", aVote(electeurs, tailleE,"POKEM", "Dane"));    //Ca retourne ici 1 si l'electeur  a voté, 0 s'il n'a pas voté et -1 si ca ne trouve pas le nom entré
    printf("Meli -> %d\n", aVote(electeurs, tailleE, "MELI", "Ange"));
    printf("Xavier -> %d\n", aVote(electeurs, tailleE, "TT", "Xavier"));

    return 0;
} */
