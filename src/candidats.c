#include "../include/candidats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void annoncerCandidats() {
    FILE *f = fopen("database/candidats.csv", "r");
    if (!f) {
        printf("Erreur : fichier candidats.csv introuvable.\n");
        return;
    }

    Candidats c;
    char ligne[256];
    printf("\n==== LISTE DES CANDIDATS ====\n");
    while (fgets(ligne, sizeof(ligne), f)) {
        if (sscanf(ligne, "%d;%49[^;];%49[^;];%49[^;];%99[^;];%lf",
                   &c.id, c.nom, c.prenom, c.parti, c.photo, &c.caution) == 6) {
            printf("\n%s %s (%s)\n",c.prenom, c.nom, c.parti);
            printf("Age : %s ans\n----------------------------------", c.photo);

           
        }
    }

    fclose(f);
}

ResultatVote compteVote(Electeur tabE[], int tailleE, Candidat tabC[], int tailleC){
    ResultatVote resultat = {.i=0, .j= 0, .k= 0};
    int compte= 0;
    for(int i = 0; i< tailleC; i++){
        compte= 0;
        for(int j= 0; j<tailleE; j++){
            if(tabE[j].choix== tabC[i].id ){
                compte++;
            }
        }
        resultat.nbVote[resultat.i++]= compte;
        resultat.candidat[resultat.j++]= tabC[i];
        resultat.pourcent[resultat.k++]= (float)compte/tailleE*100;
    }
    return resultat;
}
