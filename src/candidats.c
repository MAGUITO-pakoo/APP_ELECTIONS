#include "../include/candidats.h"
#include "../include/electeurs.h"
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

